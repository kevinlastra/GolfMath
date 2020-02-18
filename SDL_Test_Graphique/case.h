#ifndef __CASE_H__
#define __CASE_H__

class Case
{
public:
	enum Type {water, sand, green, start, hole, NONE};
private:
	Type type;
	int portee, pos_x, pos_y;
public:
	Case();
	Case(Type, int);
	~Case();

	PosCase(int, int);
	PrintCase(Type, SDL_Surface, int, int);

	Type getType();
	int getPortee();

	void setType(Type);
	void setPortee(int);
};

#endif