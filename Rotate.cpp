/*
 * Rotate.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Patrick
 */
#include <iostream>
#include <vector>

struct point
{
	point(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
	void move(point change)
	{
		x += change.x;
		y += change.y;
	}

	void print()
	{
		std::cout<<"("<<x<<","<<y<<")";
	}
};

enum BlockType
{
	I=0,
	J,
	L,
	O,
	S,
	T,
	Z
};

enum BlockDirection
{
	NORTH,
	WEST,
	SOUTH,
	EAST
};

struct block
{
	block(BlockType type)
	{
		switch(type)
		{
		case I:
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			points.push_back(point(3,1));
			this->type = I;
			break;
		case J:
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			points.push_back(point(2,2));
			this->type = J;
			break;
		case L:
			points.push_back(point(0,2));
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			this->type = L;
			break;
		case O:
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(2,2));
			points.push_back(point(2,1));
			this->type = O;
			break;
		case S:
			points.push_back(point(0,2));
			points.push_back(point(1,2));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			this->type = S;
			break;
		case T:
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(2,1));
			this->type = T;
			break;
		case Z:
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(2,2));
			this->type = Z;
			break;
		default:
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			points.push_back(point(3,1));
			this->type = I;
			break;
		}
	}

	BlockType type;
	BlockDirection direction = SOUTH;
	std::vector<point> points;

	/**
	 * TEST FUNCTION FOR ROTATING DIFFERENT TYPES OF BLOCKS
	 * LEFT ROTATION IS TRUE BY DEFAULT...
	 * FOR RIGHT ROTATION FALSE BOOLEAN PARAMETER REQUIRED
	 */
	void Rotate(bool isLeft = true)
	{
		//I ROTATION
		if(type == I)
		{
			if(direction == SOUTH)
			{
				for(size_t i = 0; i<points.size();i++)
				{
					points[i].move(point(2-i,2-i));
					direction = EAST;
				}
			}
			else
			{
				for(size_t i = 0; i<points.size();i++)
				{
					points[i].move(point((2-i)*-1,(2-i)*-1));
					direction = SOUTH;
				}
			}
		}
		//J ROTATION
		else if(type == J)
		{
			if((direction == SOUTH && isLeft) || (direction == WEST && !isLeft))
			{
				points[0].move(point(1,1));
				points[2].move(point(-1,-1));
				points[3].move(point(0,-2));
				if(isLeft)
				{
					direction = EAST;
				}
				else
				{
					direction = NORTH;
				}
			}
			else if((direction == EAST && isLeft) || (direction == SOUTH&& !isLeft))
			{
				points[0].move(point(1,-1));
				points[2].move(point(-1,1));
				points[3].move(point(-2,0));
				if(isLeft)
				{
					direction = NORTH;
				}
				else
				{
					direction = WEST;
				}
			}
			else if((direction == NORTH && isLeft)|| (direction == EAST&& !isLeft))
			{
				points[0].move(point(-1,-1));
				points[2].move(point(1,1));
				points[3].move(point(0,2));
				if(isLeft)
				{
					direction = WEST;
				}
				else
				{
					direction = SOUTH;
				}
			}
			else if((direction == WEST && isLeft)|| (direction == NORTH&& !isLeft))
			{
				points[0].move(point(-1,1));
				points[2].move(point(1,-1));
				points[3].move(point(2,0));
				if(isLeft)
				{
					direction = SOUTH;
				}
				else
				{
					direction = EAST;
				}
			}
		}
		else if(type == L)
		{
			std::cout<<"L ROTATION NOT IMPLEMENTED"<<std::endl;
		}
		else if(type == S)
		{
			std::cout<<"S ROTATION NOT IMPLEMENTED"<<std::endl;
		}
		else if(type == T)
		{
			std::cout<<"T ROTATION NOT IMPLEMENTED"<<std::endl;
		}
		else if(type == Z)
		{
			std::cout<<"Z ROTATION NOT IMPLEMENTED"<<std::endl;
		}
	}


	void print()
	{
		for(auto el: points)
		{
			el.print();
			std::cout<<" ";
		}
		switch(direction)
		{
		case SOUTH:
			std::cout<<"Block Direction:SOUTH"<<std::endl;
			break;
		case EAST:
			std::cout<<"Block Direction:EAST"<<std::endl;
			break;
		case NORTH:
			std::cout<<"Block Direction:NORTH"<<std::endl;
			break;
		case WEST:
			std::cout<<"Block Direction:WEST"<<std::endl;
			break;
		}
		std::cout<<std::endl;
	}
};

void DisplayBlock(block b)
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			int counter = 0;
			bool marked = false;
			for(auto el: b.points)
			{
				if(el.x == j && el.y == i)
				{
					marked = true;
					break;
				}
				counter++;
			}
			if(marked)
			{
				std::cout<<" "<<counter;
			}
			else
			{
				std::cout<<" *";
			}
//			std::cout<<"("<<j<<","<<i<<")";
		}
		std::cout<<std::endl;
	}
}

void TestBlockRotation(block block,char designation) {

	bool right{false};

	std::cout << "******'"<<designation<<"' block **********" << std::endl;
	std::cout << "'"<<designation<<"' block start:" << std::endl;
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated left once:" << std::endl;
	block.Rotate();
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated left twice:" << std::endl;
	block.Rotate();
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated left Three Times:" << std::endl;
	block.Rotate();
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated left Four Times:" << std::endl;
	block.Rotate();
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout<<"//////////////////////////RIGHT ROTATION START////////////////////////////////"<<std::endl;
	std::cout << "******'"<<designation<<"' block **********" << std::endl;
	std::cout << "'"<<designation<<"' block start:" << std::endl;
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated right once:" << std::endl;
	block.Rotate(right);
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated right twice:" << std::endl;
	block.Rotate(right);
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated right Three Times:" << std::endl;
	block.Rotate(right);
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated right Four Times:" << std::endl;
	block.Rotate(right);
	DisplayBlock(block);
	block.print();
	std::cout << std::endl;
}

int main()
{
	std::cout<<"Hi world"<<std::endl;
	std::cout<<std::endl;
	block IBlock = block(I);
	block JBlock = block(static_cast<BlockType>(1));
	block LBlock = block(L);
	block OBlock = block(O);
	block SBlock = block(S);
	block TBlock = block(T);
	block ZBlock = block(Z);

	TestBlockRotation(JBlock,'J');
	return 0;
}


