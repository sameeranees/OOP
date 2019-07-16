#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

LinkedList::LinkedList() //constructor
{
    head = NULL;
    tail = NULL;
    GameOver = false;
}

void LinkedList::Push(GameObject* obj)//pushes object into linked list
{
    if(head == NULL) // if head node is empty
    {
        head = new Node;//  makes new node
        head->gameobject = obj; // assigns gameobject
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        //if there is anode the value is assigned in node after tail node
        tail->next = new Node;
        Node* temp = tail;
        tail = tail->next;
        tail->prev = temp;
        tail->next = NULL;
        tail->gameobject = obj;
    }
}

bool LinkedList::CheckMoney(int money,SDL_Renderer* gRenderer)//following function checks money in head node which is throne
{
    tail->gameobject->SetMoney(money);//first it sets money to the tail object then it calls update function which return if there is money to render a tower
    if(head->gameobject->Update(tail->gameobject,gRenderer)==false)
    {
        //if there is not enough money then it removes tower from linked list
        Node* temp2 = tail;
        tail=tail->prev;
        Delete(temp2);
    }
    return true;
}
void LinkedList::Save() // the following function saves objects into save file
{
    ofstream GameSave( "game_save.txt" ); // writes into save file
    Node* temp=head;
    //it goes through the linked list and checks the type of objects. Then its saves its type,its coordinates, its money and its health
    while(temp!=NULL)
    {
        if(temp->gameobject->IsThrone()==true)
        {
            GameSave<<"Throne"<<"\n";
            GameSave<<temp->gameobject->GiveMoney()<<" ";
            GameSave<<temp->gameobject->GetHealth()<<"\n";
        }
        else if(temp->gameobject->ISEnemy()==true)
        {
            GameSave<<temp->gameobject->EnemyType()<<"\n";
            GameSave<<temp->gameobject->GetX()<<" ";
            GameSave<<temp->gameobject->GetY()<<" ";
            GameSave<<temp->gameobject->GetHealth()<<"\n";
        }
        else if(temp->gameobject->ISTower()==true)
        {
            GameSave<<temp->gameobject->TowerType()<<"\n";
            GameSave<<temp->gameobject->GetX()<<" ";
            GameSave<<temp->gameobject->GetY()<<" ";
            GameSave<<temp->gameobject->GiveMoney()<<"\n";
        }
        temp=temp->next;
    }
}

void LinkedList::Delete(Node* del) // following deletes node
{
    /* base case */
    if (head == NULL || del == NULL)

    /* If node to be deleted is head node */
    if (head == del)
        head = del->next;

    /* Change next only if node to be deleted is NOT
       the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT
       the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    delete del;
}

int LinkedList::Size() // return size of linked list
{
    int i = 0;// increments i until node is empty
    Node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}

void LinkedList::Clear() // clears the whole list
{
    while(head != NULL) // deletes until head is null
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

LinkedList::~LinkedList()//destructor clears the list
{
    Clear();
}

void LinkedList::Show(SDL_Renderer * gRenderer, long int frame) // the following function carried all types of procedures in gameobjects
{
    Node*temp=head->next;
    head->gameobject->Draw(gRenderer);// drwas the throne
    while(temp!=NULL)
    {
        Node *temp3=head;
        temp->gameobject->Draw(gRenderer);// draws the current gameobject
        while(temp3!=NULL)
        {
            if(temp!=temp3)
            {
                if(temp->gameobject->Update(temp3->gameobject,gRenderer)==true) //This statement checks if tower has attacked enemy and reduces it's health if it has. It will also call enemy update which will reduce throne health when attacked
                {
                    if(temp3->gameobject->GetHealth()<=0)//if enemy health is less than 0 then it deletes the enemy from the list
                    {
                        head->gameobject->IncreaseMoney(500);//it also increases money for throne
                        head->gameobject->Update(temp3->gameobject,gRenderer);//it also updates the throne
                        Node* temp2 = temp3;
                        if(temp3->next!=NULL)
                        {
                            temp3 = temp3->next;
                            temp3->prev = temp2->prev;
                        }
                        else
                        {
                            tail=temp3->prev;
                        }
                        Delete(temp2);
                    }

                }
                if(temp3->gameobject->GetHealth()<=0 && temp3->gameobject->ISEnemy()==true)// checks if current enemy has health below 0. if it has then it it deletes from list
                {
                    Node* temp2 = temp3;
                    if(temp3->next!=NULL)
                    {
                        temp3 = temp3->next;
                        temp3->prev = temp2->prev;
                    }
                    else
                    {
                        tail=temp3->prev;
                    }
                    Delete(temp2);
                }
            }
            if(temp3!=NULL)// checks if temp3 is not null
            {
                temp3=temp3->next;
            }
        }
        temp=temp->next;// increments temp
        delete temp3;// frees temp3
    }
    delete temp;// frees temp
    if (head->gameobject->GetHealth()<=0)// checks if throne health is below 0. if it is then it shows gameover screen.
    {
        GameOver = true;
    }
}

bool LinkedList::isGameOver()// checks if gameover is true.
{
    return GameOver;
}
