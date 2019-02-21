#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <termios.h>
#include <sys/time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

char** map;//map정보를 담을 변수 생성.
char** firstmap;//초기 map정보를 지닌 변수
int row, col;//map의 가로, 세로 길이  변수

typedef struct
{
	int r; // row index value
	int c; // column index value
}COOR;

typedef struct
{
	int len; // total length of the snake
	struct node* face; // points the first real node of the snake
}SNAKE;

typedef struct node
{
	COOR rc; // coordinate of the node
	int dir; // direction where the node heads to
	short isPattern; // flag for pattern (O or X)
	short isFace; // flag for the first node (@)
	//snake의 맨 처음일 경우 isPattern = 0, isFace = '@'
	//snake의 몸통일 경우 isPattern = O or X, isFace = 0
	struct node* link;
}SNAKE_NODE;
//Snake의 정보를 담은 변수 정의

SNAKE* snake;//snake의 정보를 갖는 변수를 선언
COOR F, P, S;

// DO NOT remove following variables
int time_out, game_over;


/* Usage of other user function is also allowed */


void drawSnake(){
    /* TODO: draw whole snake */
	SNAKE_NODE* cur = snake->face;
	int count = 1;
	while(1)
	{
		if(cur->isPattern == 0)
		{
			map[cur->rc.r][cur->rc.c] = cur->isFace;
		}
		else if(cur->isFace == 0)
		{
			map[cur->rc.r][cur->rc.c] = cur->isPattern;
		}
		if(cur->link == NULL)
		{
			break;
		}
		cur = cur->link;
	}
	//SNAKE_NODE들을 순차적으로 map에 지정해준다. 이 때 머리와 몸통을 구분하여 지정해준다.

    
 }


void makeItem() {
	/* 
     * TODO: generate COOR for each item and place them on map[][]
     * 1. Feed: add node at the end of the snake
     * 2. Poison: delete node at the end of the snake
     * 3. Snack: change pattern of first body node
     */
	srand(time(NULL));

	while(1)
	{
		F.r = rand() % (row - 1);
		F.c = rand() % (col - 1);
		if(map[F.r][F.c] == ' ')
		{
			map[F.r][F.c] = 'F';
			break;
		}
	}
	while(1)
	{
		P.r = rand() % (row - 1);
		P.c = rand() % (col - 1);
		if(map[P.r][P.c] == ' ')
		{
			map[P.r][P.c] = 'P';
			break;
		}
	}
	while(1)
	{
		S.r = rand() % (row - 1);
		S.c = rand() % (col - 1);
		if(map[S.r][S.c] == ' ')
		{
			map[S.r][S.c] = 'S';
			break;
		}
	}
	//Item의 위치를 새로 설정해준다. 만약 rand의 결과값의 좌표의 값이 ' '가 아니라면 반복문을 통해 새로운 수를 입력받는다.


}

void drawBoard() {
    
    system("clear"); // clear screen
    puts("");
    printf("Snake Game\n");
    puts("");
 
    /* TODO: draw Board, snake and items*/
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			*(*(map + i) + j) = *(*(firstmap + i) + j);
		}
	}//map에 초기 정보를 지닌 firstmap을 덮어씌운다. 
	map[F.r][F.c] = 'F';
	map[P.r][P.c] = 'P';
	map[S.r][S.c] = 'S';//item의 위치를 map에 전달해 넣어준다.
	
	drawSnake();//map에 snake의 정보를 넣어준다.
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%c", *(*(map + i) + j));
		}
		printf("\n");
	}//그 후 item과 snake의 정보를 전달받은 map을 그린다.

}

void init() {
	/*
     * TODO:
     * 1. read the map from board.txt
     * 2. malloc SNAKE node
     * 3. malloc SNAKE_NODE face node
     * 4. make initial position of items
     */
    // user code
	srand(time(NULL));
	FILE* txt;
	txt = fopen("board.txt", "r");
	fscanf(txt, "%d %d", &row, &col);
	//행, 열 값 받아오기
	map = (char**)malloc(sizeof(char*)*row);
	firstmap = (char**)malloc(sizeof(char*)*row);
	for(int i = 0; i < row; i++)
	{
		*(map + i) = (char*)malloc(sizeof(char)*col);
		*(firstmap + i) = (char*)malloc(sizeof(char)*col);
	}//map,firstmap 에 동적 할당(행과 열 만큼)
	int temp;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			fscanf(txt, "%1d", &temp);
			if(temp == 1)
			{
				*(*(map + i) + j) = '*';
				*(*(firstmap + i) + j) = '*';
			}
			else if(temp == 0)
			{
				*(*(map + i) + j) = ' ';
				*(*(firstmap + i) + j) = ' ';
			}
		}
	}//map과 firstmap 에 board.txt파일의 정보에 맞게 '*'과 ' '을 넣어줌
	SNAKE_NODE* head;
	snake = (SNAKE*)malloc(sizeof(SNAKE));
	head = (SNAKE_NODE*)malloc(sizeof(SNAKE_NODE));

	snake->len = 1;
	snake->face = head;

	(head->rc).r = (row / 2);
	(head->rc).c = (col / 2);
	head->dir = -1;
	head->isFace = '@';
	head->isPattern = 0;
	head->link = NULL;
	//snake와 head의 기본 정보를 입력해준다.
	
	while(1)
	{
		F.r = rand() % (row - 1);
		F.c = rand() % (col - 1);
		if(map[F.r][F.c] == ' ')
		{
			map[F.r][F.c] = 'F';
			break;
		}
	}
	while(1)
	{
		P.r = rand() % (row - 1);
		P.c = rand() % (col - 1);
		if(map[P.r][P.c] == ' ')
		{
			map[P.r][P.c] = 'P';
			break;
		}
	}
	while(1)
	{
		S.r = rand() % (row - 1);
		S.c = rand() % (col - 1);
		if(map[S.r][S.c] == ' ')
		{
			map[S.r][S.c] = 'S';
			break;
		}
	}//makeItem 함수와 같은 방식으로 Item들의 초기 위치를 설정해준다. 


	fclose(txt);
    // user code end
	game_over = 0;
	time_out = 0;
}
   




/* call by ualarm( microsec ) */

int temp_do_count = 0;

void Do(int sig) {
	system("clear");
	//printf("Alarm %d!\n", ++temp_do_count);
    /* TODO:
     * 1. set the COOR of the snake by its heading direction
     * 2. what to do when face meets an item(F, P, S)
     * 3. game_over condition 
     */
	COOR temp1, temp2;//이전 노드의 좌표값을 저장하는 변수들이다.
	
	SNAKE_NODE* cur, *pre;//노드의 삽입, 해제에서 역할하는 포인터이다.
	cur = snake->face;
	pre = snake->face;
	if(snake->face->dir == 0)
	{
		temp1.r = snake->face->rc.r;
		temp2.r = snake->face->rc.r;
		temp1.c = snake->face->rc.c;
		temp2.c = snake->face->rc.c;
		(snake->face->rc.c)++;
		while(1)
		{
			if(snake->len == 1)
			{
				break;
			}
			else
			{
				cur = cur->link;
				temp2.r = cur->rc.r;
				temp2.c = cur->rc.c;
				cur->rc.r = temp1.r;
				cur->rc.c = temp1.c;
				temp1.r = temp2.r;
				temp1.c = temp2.c;

				if(cur->link == NULL)
				{
					break;
				}
			}
		}
	}
	else if(snake->face->dir == 1)
	{
		temp1.r = snake->face->rc.r;
		temp2.r = snake->face->rc.r;
		temp1.c = snake->face->rc.c;
		temp2.c = snake->face->rc.c;
		(snake->face->rc.r)--;

		while(1)
		{
			if(snake->len == 1)
			{
				break;
			}
			else
			{
				cur = cur->link;
				temp2.r = cur->rc.r;
				temp2.c = cur->rc.c;
				cur->rc.r = temp1.r;
				cur->rc.c = temp1.c;
				temp1.r = temp2.r;
				temp1.c = temp2.c;

				if(cur->link == NULL)
				{
					break;
				}
			}
		}
	}
	else if(snake->face->dir == 2)
	{
		temp1.r = snake->face->rc.r;
		temp2.r = snake->face->rc.r;
		temp1.c = snake->face->rc.c;
		temp2.c = snake->face->rc.c;
		(snake->face->rc.c)--;

		while(1)
		{
			if(snake->len == 1)
			{
				break;
			}
			else
			{
				cur = cur->link;
				temp2.r = cur->rc.r;
				temp2.c = cur->rc.c;
				cur->rc.r = temp1.r;
				cur->rc.c = temp1.c;
				temp1.r = temp2.r;
				temp1.c = temp2.c;

				if(cur->link == NULL)
				{
					break;
				}
			}
		}
	}
	else if(snake->face->dir == 3)
	{
		temp1.r = snake->face->rc.r;
		temp2.r = snake->face->rc.r;
		temp1.c = snake->face->rc.c;
		temp2.c = snake->face->rc.c;
		(snake->face->rc.r)++;

		while(1)
		{
			if(snake->len == 1)
			{
				break;
			}
			else
			{
				cur = cur->link;
				temp2.r = cur->rc.r;
				temp2.c = cur->rc.c;
				cur->rc.r = temp1.r;
				cur->rc.c = temp1.c;
				temp1.r = temp2.r;
				temp1.c = temp2.c;

				if(cur->link == NULL)
				{
					break;
				}
			}
		}
	}
	//입력받은 command값을 바탕으로 설정된 뱀의 방향을 바탕으로 뱀을 이동시킨다. 이 때 cur가 뱀의 마지막 노드를 가르키도록 하고, temp1, temp2에 마지막 노드의 이동 전 좌표를 저장한다.
	
	if(map[snake->face->rc.r][snake->face->rc.c] == 'F')
	{
		SNAKE_NODE* new;
		new = (SNAKE_NODE*)malloc(sizeof(SNAKE_NODE));
		new->link = NULL;
		new->isFace = 0;
		new->isPattern = 'O';
		new->rc.r = temp2.r;
		new->rc.c = temp2.c;
		
		cur->link = new;
		(snake->len)++;
		makeItem();
	}
	//뱀의 head의 위치에 F가 있을 경우 뱀의 가장 끝에 몸통을 추가해준다. 이 때 그 위치는 temp2 값을 이용해 지정해준다. 이후 makeItem을 이용하여 Item의 위치를 바꿔준다.

	if(map[snake->face->rc.r][snake->face->rc.c] == 'P')
	{
		if(snake->len != 1)
		{
			SNAKE_NODE* last = snake->face;
			while(1)
			{
				last = last->link;
				if(last->link == NULL)
					break;
				pre = last;
			}
			pre->link = NULL;
			map[last->rc.r][last->rc.c] = ' ';
			free(last);
			(snake->len)--;
			makeItem();
		}
		else
		{
			makeItem();
		}
	}
	//뱀의 가장 끝 노드를 없애고 메모리 할당을 해제한다. 만약 snake->len 이 1이었다면 makeItem으로 Item들의 위치만 바꿔준다.

	if(map[snake->face->rc.r][snake->face->rc.c] == 'S')
	{
		SNAKE_NODE* change = snake->face;
		if(snake->len == 1)
		{
			makeItem();
		}
		else
		{
			change = change->link;
			while(1)
			{
				if(change->isPattern == 'O')
				{
					change->isPattern = 'X';
					break;
				}
				else
				{
					if(change->link == NULL)
					{
						break;
					}
					change = change->link;
				}
			}
			makeItem();
		}
	}
	//뱀의 머리 뒤의 노드부터 순차적으로 'O'에서 'X'로 바꿔준 후 makeItem을 이용하여 Item들의 위치를 바꿔준다. 만약 snake->len이 1이라면 Item들의 위치만 바꿔주었다. 
	
	




    // 3. game_over condition 
	if(map[snake->face->rc.r][snake->face->rc.c] == '*' || map[snake->face->rc.r][snake->face->rc.c] == 'O' || map[snake->face->rc.r][snake->face->rc.c] == 'X')
	{
		game_over = 1;
	}
	//만약 head의 좌표에 있는 map의 값이 '*' 거나 'O' 거나 'X'라면 게임이 종료되도록 설정한다.
    /* time out variable update */
	time_out = 0;
}

/* get key charater directly */
int getch(void)
{
	char   ch;
	int   error;
	static struct termios Otty, Ntty;

	fflush(stdout);
	tcgetattr(0, &Otty);
	Ntty = Otty;
	Ntty.c_iflag = 0;
	Ntty.c_oflag = 0;
	Ntty.c_lflag &= ~ICANON;
#if 1
	Ntty.c_lflag &= ~ECHO;
#else
	Ntty.c_lflag |= ECHO;
#endif
	Ntty.c_cc[VMIN] = 0;
	Ntty.c_cc[VTIME] = 1;

#if 1
#define FLAG TCSAFLUSH
#else
#define FLAG TCSANOW
#endif

	if (0 == (error = tcsetattr(0, FLAG, &Ntty)))
	{
		error = read(0, &ch, 1);
		error += tcsetattr(0, FLAG, &Otty);
	}

	return (error == 1 ? (int)ch : -1);
}


int GetCommand() {
	int ch = getch();

	switch (ch)
	{
	case 'd':
	case 'D': return 0; /* RIGHT */
	case 'w':
	case 'W': return 1; /* UP */
	case 'a':
	case 'A': return 2; /* LEFT */
	case 's':
	case 'S': return 3; /* DOWN */
	default: return -1; /* OTHER KEY */
	}

	return -1;
}


int main() {
	int command;
	init();
	srand(time(NULL));
	static struct sigaction act, oact;

	/* if call alarm or ualarm function, then call Do function/ */
	act.sa_handler = Do; /* ( signal.h header ) */
	sigaction(SIGALRM, &act, NULL);

	do {

		if (time_out == 0) {
			//alarm(1); // 1 second
			ualarm(300000, 0); // 0.3 second ( unistd.h header )
            time_out = 1;
		}
		command = GetCommand();
        // user code


		if(command == 0 && (snake->face->dir == 1 || snake->face->dir == 3) || (snake->face->dir) == -1)
		{
			snake->face->dir = command;
			Do(command);
		}
		else if(command == 1 && (snake->face->dir == 0 || snake->face->dir == 2) || (snake->face->dir == -1))
		{
			snake->face->dir = command;
			Do(command);
		}
		else if(command == 2 && (snake->face->dir == 1 || snake->face->dir == 3) || (snake->face->dir == -1))
		{
			snake->face->dir = command;
			Do(command);
		}
		else if(command == 3 && (snake->face->dir == 0 || snake->face->dir == 2) || (snake->face->dir == -1))
		{
			snake->face->dir = command;
			Do(command);
		}
		else if(command == -1)
		{
			command = snake->face->dir;
			Do(command);
		}
//입력받은 command를 snake의 방향으로 설정해준다. 이 때 진행중인 방향의 반대방향일 때는 입력받지 않은 것으로 친다.
		drawBoard();
		//Do에서 진행 된 내용을 바탕으로 Board를 새로 그려준다.
	} while (!game_over);

	//system("clear");
	printf("game over!\n");
	SNAKE_NODE* freeman = snake->face;
	SNAKE_NODE* preman = snake->face;
	while((snake->len) != 0)
	{
		if(snake->len != 1)
		{
			freeman = freeman->link;
		}
		free(preman);
		preman = freeman;
		(snake->len)--;
	}
	free(snake);
	for(int i; i < col; i++)
	{
		free(*(map + i));
		free(*(firstmap + i));
	}
	free(map);
	free(firstmap);
	//종료 전 게임에 사용된 node들과 snake에 할당된 메모리를 해제한다. map과 firstmap 역시 할당된 메모리를 해제해준다. 
}
