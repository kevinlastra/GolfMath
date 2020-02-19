#include <SDL/SDL.h>
#include "case.h"
#include <SDL/SDL_image.h>
#include <string.h>

Case::Case() : type(NONE), portee(0){}
Case::Case(Type t, int i) : type(t), portee(i)
{
	SDL_Surface *tshape = NULL;

	string c = t + '/' + t + '_' + i + '.jpg';

	tshape = IMG_Load(c);
} 
Case::PosCase(int x, int y) : pos_x(x), pos_y(y)
{
	SDL_Rect tpos;

	tpos.x = x;
	tpos.y = y;
}
Case::PrintCase()
{

}