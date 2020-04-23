#include"commonFunc.h"
#include "BaseObject.h"
#include "mainObject.h"
#include "game_map.h"
#include "ThreatsObject.h"
#include<ctime>
BaseObject g_background;
SDL_Surface* g_object = NULL;


bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0)
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

    g_window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,
                                SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
    }
    return success;
}

bool LoadBackGround()
{
    bool ret = g_background.LoadImg("img//background.png", g_screen);
    if(ret = false)
        return false;
    else return true;
}
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}


void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[])
{
    if(InitData() == false)
        return -1;
    if(LoadBackGround() == false)
        return -1;

    GameMap game_map;
    game_map.LoadMap("map\\map.dat");
    game_map.LoadTiles(g_screen);

    bool is_quit = false;

    MainObject p_player;
    p_player.LoadImg("img//bird2.png",g_screen);
    p_player.set_clips();

    //make threats
    ThreatObject* p_threat =  new ThreatObject();
    bool ret = p_threat ->LoadImg("img/threat.png",g_screen);
    if(ret == false) return 10;
    p_threat ->SetRect(1000,-200);
    p_threat->set_x_val(1);


    while(!is_quit)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }

            p_player.HandleInputAction(g_event, g_screen);
        }



        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR );
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen,NULL);
        p_player.Show(g_screen);


        //game_map.DrawMap(g_screen);
        p_threat->Show_1(g_screen);
        p_threat->HandleMove(SCREEN_WIDTH,SCREEN_HEIGHT);

         SDL_RenderPresent(g_screen);
    }

    close();
    return 0;
}








