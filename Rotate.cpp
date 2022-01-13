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
//		blocks.push_back(TBlock(Vec2D(0,0),blockSize,Color::Blue()));
//		blocks.push_back(TBlock(Vec2D(1,0),blockSize,Color::Blue()));
//		blocks.push_back(TBlock(Vec2D(2,0),blockSize,Color::Blue()));
//		blocks.push_back(TBlock(Vec2D(2,1),blockSize,Color::Blue()));
			points.push_back(point(0,1));
			points.push_back(point(1,1));
			points.push_back(point(2,1));
			points.push_back(point(2,2));
			this->type = J;
			break;
		case L:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = L;
			break;
		case O:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = O;
			break;
		case S:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = S;
			break;
		case T:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = T;
			break;
		case Z:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = Z;
			break;
		default:
			points.push_back(point(1,0));
			points.push_back(point(1,1));
			points.push_back(point(1,2));
			points.push_back(point(1,3));
			this->type = I;
			break;
		}
	}

	BlockType type;
	BlockDirection direction = NORTH;
	std::vector<point> points;
	void rotateLeft()
	{
		if(type == I)
		{
			if(direction == NORTH)
			{
				for(size_t i = 0; i<points.size();i++)
				{
					points[i].move(point(2-i,2-i));
					direction = WEST;
				}
			}
			else
			{
				for(size_t i = 0; i<points.size();i++)
				{
					points[i].move(point((2-i)*-1,(2-i)*-1));
					direction = NORTH;
				}
			}
		}
		else if(type == J)
		{
			std::cout<<"J ROTATION NOT IMPLEMENTED"<<std::endl;
		}
	}


	void print()
	{
		for(auto el: points)
		{
			el.print();
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}
};

void printblock(block b)
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
	std::cout << "******'"<<designation<<"' block **********" << std::endl;
	std::cout << "'"<<designation<<"' block start:" << std::endl;
	printblock(block);
	block.print();
	std::cout << std::endl;

	std::cout << "'"<<designation<<"' Block Rotated left once:" << std::endl;
	block.rotateLeft();
	printblock(block);
	block.print();
	std::cout << std::endl;
	std::cout << "'"<<designation<<"' Block Rotated left twice:" << std::endl;
	block.rotateLeft();
	printblock(block);
	block.print();
	std::cout << std::endl;
}

int main()
{
	std::cout<<"Hi world"<<std::endl;
	std::cout<<std::endl;
	block IBlock = block(I);
	block JBlock = block(static_cast<BlockType>(1));

	TestBlockRotation(JBlock,'J');
	return 0;
}


