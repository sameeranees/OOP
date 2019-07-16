/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/


#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include"Shape.h"
#include "Stack.h"
#include "cstdlib"
#include "time.h"
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );


			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
    int rectx1;
    int rectx2;
    int rectx3;
    int rectx4;
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		if( !loadMedia() )  //Load media
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;  //Main loop controller

			SDL_Event e;        //Event handler that takes care of all events

			bool mouseClicked = false;
			//3 bool values to switch between rectangle draw, point draw, and line draw
			bool defalt=true;
			bool ppress=false;
			bool lpress=false;
			SDL_Rect fillRect;
			//values for rectangle
			int oldx = 0;
            int oldy = 0;
            srand(time(NULL));
            //3 stacks defined
            Stack* stck=NULL; //stck main stack that stores all drawn objects
            Stack* redostack=NULL; //every object undo'd goes into redostack
            Stack* stck2=NULL; //used as an extra stack to reverse order of objects stored in stck
            redostack = new Stack;
            stck2 = new Stack;
            Shape* shape = NULL;
            stck=new Stack;
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); //show white screen
            SDL_RenderClear( gRenderer );
            cout << "DRAW RECTANGLE BY DEFAULT. TO SWITCH BETWEEN RECTANGLE, POINT & LINE, PRESS R/P/L RESPECTIVELY. \nPRESS RIGHT CLICK TO UNDO, MIDDLE CLICK TO REDO, UP TO MOVE OBJECT UP, DOWN TO MOVE OBJECT DOWN. \nENJOY!\n";
			//While application is running
			while( !quit )
			{
			    SDL_SetRenderDrawColor( gRenderer, rand()%256, rand()%256, rand()%256, rand()%256 );
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{

					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					 if(e.type==SDL_KEYDOWN) //if a key is pressed
                     {
                        switch (e.key.keysym.sym)
                        {
                            //match key press for each case below
                            case SDLK_p: //if p is pressed set ppress to true
                                {
                                    ppress=true;
                                    defalt=false;
                                    lpress=false;
                                    break;
                                }
                            case SDLK_l: //if l is pressed set lpress to true
                                {
                                    lpress=true;
                                    defalt=false;
                                    ppress=false;
                                    break;
                                }
                            case SDLK_r: //if r is pressed set rpressed to true
                                {
                                    defalt=true;
                                    lpress=false;
                                    ppress=false;
                                }
                        }
                     }
                    if (defalt==true)
                    {
                        if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                        {
                        //Get mouse position
                            int x, y;
                            SDL_GetMouseState( &x, &y );

                            if(e.type ==  SDL_MOUSEMOTION)
                            {
                                if(mouseClicked == true)
                                {

                                    fillRect = { oldx , oldy , x - oldx, y - oldy };
                                }
                            }
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_LEFT)
                                {
                                    if(mouseClicked == false)
                                    {
                                        mouseClicked = true;
                                        oldx = x;
                                        oldy = y;
                                    }

                                }
                            }

                            if(e.type == SDL_MOUSEBUTTONUP && mouseClicked == true)
                            {
                                mouseClicked = false;
                                shape= new Rect(&fillRect); //make new Rectangle
                                //the next step assigns the shape it's color so that everytime it's redrawn it uses the same color
                                shape->SetColors(rand()%256, rand()%256, rand()%256, rand()%256);
                                stck->Push(shape); //push the shape into stck
                                //the next step clears redostack - in case we undo'd a few shapes and draw a new shape, the previous shapes stored in redostack are no longer needed
                                redostack->Clear();
                                stck->Draw(gRenderer); //draw the shape
                                cout << "Rectangle Drawn" << endl;
                            }

                            if (e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_RIGHT) //if right button pressed start undo process
                                    {
                                            {
                                                if (stck->StackCheck() != true) //only proceed if stack is not empty
                                                {

                                                    redostack->Push(stck->Pop()); //pop shape from stck and push into redostack
                                                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                                                    SDL_RenderClear(gRenderer); //clear the screen
                                                    while(stck->StackCheck()!=true) //now push all items into stck2 from stck to reverse order
                                                    {
                                                        stck2->Push(stck->Pop());
                                                    }
                                                    stck2->Drawwhole(gRenderer); //draw whole stck2 - in real time this gives undo effect
                                                    while(stck2->StackCheck()!=true)
                                                    {
                                                        stck->Push(stck2->Pop()); //reverse the order again back into stck
                                                    }
                                                    cout << "UNDO" << endl;
                                                }
                                            }
                                    }
                            }
                            if(e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                if(e.button.button==SDL_BUTTON_MIDDLE && redostack->StackCheck() != true )
                                {
                                    stck->Push(redostack->Pop()); //take shape from redostack and push into stck
                                    stck->Draw(gRenderer); //draw stck head
                                    cout << "REDO" << endl;

                                }
                            }
                        }
                        if (e.type == SDL_KEYDOWN)
                        {

                            if (e.key.keysym.sym == SDLK_DOWN)
                            {
                                stck->Down(); //move shape down
                                stck->Draw(gRenderer);
                            }
                        }
                        if (e.type == SDL_KEYDOWN)
                        {
                            if (e.key.keysym.sym == SDLK_UP)
                            {
                                stck->Up(); //move shape up
                                stck->Draw(gRenderer);
                            }
                        }
                    }
                    if (ppress==true)
                    {
                        if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                        {
                        //Get mouse position
                            int x, y;
                            SDL_GetMouseState( &x, &y );

                            if(e.type ==  SDL_MOUSEMOTION)
                            {
                                if(mouseClicked == true)
                                {
                                }
                            }
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_LEFT)
                                {
                                    if(mouseClicked == false)
                                    {
                                        mouseClicked = true;
                                        oldx = x;
                                        oldy = y;
                                    }

                                }
                            }

                            if(e.type == SDL_MOUSEBUTTONUP  && mouseClicked == true)
                            {
                                mouseClicked = false;
                                shape=new Point(x,y);
                                shape->SetColors(rand()%256, rand()%256, rand()%256, rand()%256);
                                stck->Push(shape);
                                redostack->Clear();
                                stck->Draw(gRenderer);
                                cout << "Point Drawn" << endl;
                            }

                            if (e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_RIGHT)
                                    {
                                            {
                                                if (stck->StackCheck() != true)
                                                {
                                                    redostack->Push(stck->Pop());
                                                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                                                    SDL_RenderClear(gRenderer);
                                                    while(stck->StackCheck()!=true)
                                                    {
                                                        stck2->Push(stck->Pop());
                                                    }
                                                    stck2->Drawwhole(gRenderer);
                                                    while(stck2->StackCheck()!=true)
                                                    {
                                                        stck->Push(stck2->Pop());
                                                    }
                                                    cout << "UNDO" << endl;
                                                }

                                            }
                                    }
                            }
                            if(e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                if(e.button.button==SDL_BUTTON_MIDDLE && redostack->StackCheck() != true )
                                {
                                    stck->Push(redostack->Pop());
                                    stck->Draw(gRenderer);
                                    cout << "REDO" << endl;

                                }
                            }
                        }
                    }
                    if (lpress==true)
                    {
                        if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                        {
                        //Get mouse position
                            int x, y;
                            SDL_GetMouseState( &x, &y );

                            if(e.type ==  SDL_MOUSEMOTION)
                            {
                                if(mouseClicked == true)
                                {
                                }
                            }
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_LEFT)
                                {
                                    if(mouseClicked == false)
                                    {
                                        mouseClicked = true;
                                        oldx = x;
                                        oldy = y;
                                    }

                                }
                            }

                            if(e.type == SDL_MOUSEBUTTONUP && mouseClicked == true)
                            {
                                mouseClicked = false;
                                shape=new Line(oldx,oldy,x,y);
                                shape->SetColors(rand()%256, rand()%256, rand()%256, rand()%256);
                                stck->Push(shape);
                                redostack->Clear();
                                stck->Draw(gRenderer);
                                cout << "Line Drawn" << endl;
                            }

                            if (e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (e.button.button == SDL_BUTTON_RIGHT)
                                    {
                                            {
                                                if (stck->StackCheck() != true)
                                                {
                                                    redostack->Push(stck->Pop());
                                                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                                                    SDL_RenderClear(gRenderer);
                                                    while(stck->StackCheck()!=true)
                                                    {
                                                        stck2->Push(stck->Pop());
                                                    }
                                                    stck2->Drawwhole(gRenderer);
                                                    while(stck2->StackCheck()!=true)
                                                    {
                                                        stck->Push(stck2->Pop());
                                                    }
                                                    cout << "UNDO" << endl;
                                                }

                                            }
                                    }
                            }
                            if(e.type==SDL_MOUSEBUTTONDOWN)
                            {
                                if(e.button.button==SDL_BUTTON_MIDDLE && redostack->StackCheck() != true )
                                {
                                    stck->Push(redostack->Pop());
                                    stck->Draw(gRenderer);
                                    cout << "REDO" << endl;

                                }
                            }
                        }
                    }
				}
                SDL_RenderPresent( gRenderer );
			}
			stck->Clear();
			delete stck;
			stck=NULL;
			stck2->Clear();
			delete stck2;
			stck2=NULL;
			redostack->Clear();
			delete redostack;
			redostack=NULL;
		}
	}
	close();
	return 0;
}

