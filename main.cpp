#include <stdio.h>
#include <stdlib.h>//���䶯̬�ڴ��õ�
#include<graphics.h>//����ege
#include<string.h>//����ѧ���Ƕ���Ϊ�ַ������͵ģ����Ժ�����ɾ�Ĳ���õ�"strcmp"�Ⱥ���
#include <conio.h>//getch()��һЩ��Ӧ�û������Ĳ�����Ҫ
#include <ege/sys_edit.h>//imputbox_getline()���������ͷ�ļ���
#define path "C:\\Users\\qq2998637256\\Desktop\\1.txt"//�궨���ļ�·��������������ļ���д����
#define W 1000//�궨��ege�Ĵ��ڵĸߺͿ�
#define H 500
typedef struct student//����һ���ṹ�����ڴ��ѧ����Ϣ����
{
    char number[20];//ѧ��
    char name[20];//����
    char gender[10];//�Ա�
    char origin[20];//��Դ��
    int score[4];//�����Ӣ������4���ɼ�

}STU;
typedef struct list//�ٶ���һ���ṹ�壬�������������͵�Ԫ�أ�һ��Ԫ�������涨��Ľṹ���������ڴ��ѧ����Ϣ
{
    STU data;
    struct list *next;//��һ���Ǹ����͵Ľṹ��ָ�룬���ڼ�¼��һ�ṹ��ĵ�ַ���Դ˹�������

}LIST;
LIST*create_list_head()//����һ���ڴ����ڴ�����ͷ����ͷ����ѧ����Ϣ
{
    LIST*head=(LIST*)malloc(sizeof(LIST));
    head->next=NULL;
    return head;
}
LIST*create_list(STU data)//����һ���ڵ㣬�����ô����Ĳ�����ֵ
{
    LIST*newlist=(LIST*)malloc(sizeof(LIST));
    newlist->data=data;
    newlist->next=NULL;
    return newlist;

}
void free_list(LIST*a)//���������ѿ��ٵ��ڴ��ͷŵ�
{
    LIST*p=a->next;
    while(p!=NULL)
    {
        LIST*q=p;
        p=p->next;
        free(q);
    }
    a->next=NULL;
}
void write_data(LIST*a)//�����������ڵ�����ͨ����fprintf����ʽ��д�����ݵ�path·���е�txt�ļ�
{
    LIST *p=a->next;
    FILE*fp=fopen(path,"w+");
    while(p!=NULL)
    {
        fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,p->data.score[0],p->data.score[1],p->data.score[2],p->data.score[3]);
        p=p->next;
    }
    fclose(fp);
}
void read_data(LIST*a)//��path·���е�txt�ļ�ͨ����fscanf����ʽ���ض�ȡ���ݵ������У��ӱ�ͷ��ʼ��ÿ��һ�У�����һ���ڵ�
{
    LIST *p=(LIST*)malloc(sizeof(LIST));LIST *tmp;
    a->next=p;
    FILE *fp=fopen(path,"r");
    if(feof(fp))
      printf("LIST IS NULL!");
    while(!feof(fp))
    {   p->next=(LIST*)malloc(sizeof(LIST));
        fscanf(fp,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,&p->data.score[0],&p->data.score[1],&p->data.score[2],&p->data.score[3]);
        tmp =p;
        p=p->next;
    }
    tmp->next=NULL;
    free(p);
    fclose(fp);
}
void print_list(LIST*a)//������ӡ�������ڿ���̨��
{
    read_data(a);
    printf("number\tname\tgender\tplace\tChinese\tmath\tEnglish\tPE\n");
    LIST*p=a->next;
    while(p!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,p->data.score[0],p->data.score[1],p->data.score[2],p->data.score[3]);
        p=p->next;
    }
    free_list(a);
}
void ege_print_list(LIST*a)//��ege�еġ�outtextreat�������ѱ�������õ������������ͼ�ν���
{
    read_data(a);char str1[200],str2[200];int tmp=30;
    sprintf(str1,"number\tname\tgender\tplace\tChinese\tmath\tEnglish\tPE\n");
    setcolor(EGERGB(0x0, 0xFF, 0x0));
    setfont(18,0,"����");
    outtextrect(0,0,W,30,str1);
    LIST*p=a->next;
    while(p!=NULL)
    {
        sprintf(str2,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,p->data.score[0],p->data.score[1],p->data.score[2],p->data.score[3]);
        outtextrect(0,tmp,W,tmp+30,str2);
        tmp+=30;
        p=p->next;
    }
    free_list(a);
}
void find_data(LIST*a)//�������ݲ������ͼ�ν���
{
    read_data(a);char str[20];
    inputbox_getline("input box","please input the number of the student who you want to find",str,sizeof(str));//����һ������򣬲����û�������������ַ�
    LIST*p=a->next;                                                                                             //�����ʹ浽��Ӧ���ַ���������
    while(strcmp(str,p->data.number)!=0)
    {
        p=p->next;
    }
    char str1[100],str2[100];
    cleardevice();
    sprintf(str1,"number\tname\tgender\tplace\tChinese\tmath\tEnglish\tPE\n");
    setcolor(EGERGB(0x0, 0xFF, 0x0));
    setfont(18,0,"����");
    outtextrect(0,0,W,30,str1);
    sprintf(str2,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,p->data.score[0],p->data.score[1],p->data.score[2],p->data.score[3]);
    outtextrect(0,30,W,60,str2);
    free_list(a);
}
void add_list_after_head(LIST*a,STU data)//�ڱ�ͷ���һ���ڵ�
{
    LIST*newlist=create_list(data);
    newlist->next=a->next;
    a->next=newlist;
}
void add_list_at_the_end(LIST*a,STU data)//�ڱ�β��һ���ڵ�
{
    LIST*p=a;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    LIST*newlist=create_list(data);
    p->next=newlist;
}
void insert_list(LIST*a,char pos[],STU data)//������ѧ�ŵ�λ�ú����һ���ڵ�
{
    LIST*p1=a;
    LIST*p2=create_list(data);
    while(strcmp(pos,a->next->data.number)!=0)
    {
        a=a->next;
    }
    p2->next=a->next;
    a->next=p2;
    a=p1;
}
void delete_list(LIST*a,char pos[])//ɾ��ָ��λ�õĽڵ�
{
    LIST *p1=a;
    LIST *p2=a->next;
    while(strcmp(p2->data.number,pos)!=0)
    {
        p1=p2;
        p2=p2->next;
    }
    p1->next=p2->next;
    free(p2);
}
//��ɾ�Ѿ����ݸ��ˣ���û���ٵ���д�ĵĹ���


void get_data(STU*a);//��ͼ�ν����£���ȡ�û����������
void init_imput(LIST*a)//��ʼ������ԭ��������д�����û���������
{
        while(1)
        {
            STU information;
            get_data(&information);

            setbuf(stdin,NULL);
            add_list_at_the_end(a,information);
            cleardevice();
            setfont(25,0,"����");xyprintf(500,0,"continue(Y/N)?");
            int tmp;
            tmp=getch();
            if(tmp==78||tmp==110)
                break;
        }
    write_data(a);
    free_list(a);
}
void del(LIST *a)//�����û���Ӧ�������Ե�ɾ��
{
    read_data(a);
    while(1)
    {
        cleardevice();setfont(25,0,"����");xyprintf(500,0,"whether to delete(y/n)?");
        int key;
        key=getch();
        if(key==89||key==121)
        {
            char t[20];
            inputbox_getline("input","inmput the number of the student you want to delete",t,sizeof(t));
            delete_list(a,t);
            cleardevice();setfont(25,0,"����");xyprintf(500,0,"Have deleted!\n");
        }
        else
            break;
    }
    write_data(a);
    free_list(a);

}
void ins(LIST*a)//�����Եز���
{
    read_data(a);
    char ch;
    while(1)
    {
        cleardevice();setfont(25,0,"����");xyprintf(500,0,"whether to insert a student(y/n)?");
        int key;
        key=getch();
        if(key==89||key==121)
        {
            STU x;
            get_data(&x);
            char y[20];
            inputbox_getline("input","input the number of the student where you want to insert:",y,sizeof(y));
            insert_list(a,y,x);
            cleardevice();setfont(25,0,"����");xyprintf(500,0,"Have inserted!\n");
        }
        else
            break;
    }
    write_data(a);
    free_list(a);

}
void ege_scoreofsubject(LIST*a,char*subject,int t)//����Ů���ֿ�Ŀ�����ɼ��á�bar������������״ͼ
{
    read_data(a);
    initgraph(W, H);
    int m=31,w=31;
    //setbkcolor(EGERGB(0xFF,0x0, 0xFF));
	setcolor(EGERGB(0xFF,0xFF,0x0));
    line(m-1,H-1,W-100,H-1);
    line(m-1,H,m-1,H/2+50);
    line(m-1,H/2,W-100,H/2);
    line(m-1,H/2,m-1,50);
    setfont(30, 0, "����");
    outtextxy(m-8, 50, "^");
    outtextxy(m-8, H/2+50, "^");
    setfont(15, 0, "����");
    outtextxy(m+10, 50, "score");
    outtextxy(m+10, H/2+50, "score");
    outtextxy(W-98, H/2-15, ">student");
    outtextxy(W-98, H-1-15, ">student");
    setcolor(EGERGB(0xFF,0xFF,0x0));
	setfont(18, 0, "����");
	outtextxy(W/4*3, H/2+30, "Man");
	outtextxy(W/4*3, 30, "Woman");
	setfont(30, 0, "����");
	outtextxy(W/2-150, 10, subject);
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	while(a->next!=NULL)
	{   if(strcmp(a->next->data.gender,"man")==0)
            {
                setfillcolor(EGERGB(0xFF, 0x0, 0x80));
                bar(m,H-1,m+30,H-(a->next->data.score[t]));setfont(10, 0, "����");xyprintf(m+15,H-20-a->next->data.score[t],a->next->data.name);
                a=a->next;
                m+=50;
            }
        else
        {
                setfillcolor(EGERGB(0x0, 0x0, 0xFF));
                bar(w,H/2,w+30,H/2-(a->next->data.score[t]));setfont(10, 0, "����");xyprintf(w+15,H/2-20-a->next->data.score[t],a->next->data.name);
                a=a->next;
                w+=50;
        }
	}
	free_list(a);
}
void weighted_average(LIST*a,float b[])//���û������Ӧ��Ŀ��Ȩֵ��ռ�ȣ��������Ȩƽ����
{
    read_data(a);int i=0;
    float c,m,e,p;
    char str[50];
    inputbox_getline("input","inmput the weight of each subject:",str,sizeof(str));
    sscanf(str,"%f%f%f%f",&c,&m,&e,&p);
    while(a->next!=NULL)
    {
        b[i]=(float)(a->next->data.score[0]*c+a->next->data.score[1]*m+a->next->data.score[2]*e+a->next->data.score[3]*p);
        a=a->next;i++;
    }
    free_list(a);
}
void sum_average_by_gender(LIST*a,float m[],float w[],float all[],int *man,int *woman)//����Ů������˵�4�ſ�Ŀƽ����
{
    read_data(a);LIST*tmp=a;
    int p1=0,p2=0,p3=0;
    while(tmp->next!=NULL)
    {
        if(strcmp(tmp->next->data.gender,"man")==0)
        {
            m[p1]=(float)((tmp->next->data.score[0]+tmp->next->data.score[1]+tmp->next->data.score[2]+tmp->next->data.score[3])/4);
            all[p3]=(float)((tmp->next->data.score[0]+tmp->next->data.score[1]+tmp->next->data.score[2]+tmp->next->data.score[3])/4);
            p1++;p3++;
        }
        else
        {
            w[p2]=(float)((tmp->next->data.score[0]+tmp->next->data.score[1]+tmp->next->data.score[2]+tmp->next->data.score[3])/4);
            all[p3]=(float)((tmp->next->data.score[0]+tmp->next->data.score[1]+tmp->next->data.score[2]+tmp->next->data.score[3])/4);
            p2++;p3++;
        }
        tmp=tmp->next;
    }
        *man=p1;*woman=p2;
    free_list(a);
}
int count_list(LIST*a)//�������ͷ��Ľڵ��������������д�����Ӻ��е�ѭ������
{
    read_data(a);int num;
    while(a->next!=NULL)
    {
        a=a->next;
        num++;
    }
    free_list(a);
    return num;
}
void variance(LIST*a)//������ʧ���ǡ���ž����������������������ſ�Ŀ�ļ�Ȩƽ�������ۺϳɼ����ٷ���Ů������ۺϳɼ���ƽ���֣���
{                    //ͨ�������ۺϳɼ���ȥ���Ӧ�Ա��ƽ���֣���������ƫ��ƽ���̶ֳȵ�����ͼ��Ȼ������ʧ���ǣ��൱����ֻ��������
                    //Ů������ƫ����ƽ���̶ֳȵ�����ͼ��Ҳ���ǰװ׼�������Ů�����ۺϳɼ�ƽ���ֶ�û���õ���
    read_data(a);
    int n=count_list(a);int x=30,y;
    float m[10],w[10],all[10];int man,woman;
    sum_average_by_gender(a,m,w,all,&man,&woman);
    float average_all=0,average_man=0,average_woman=0;
    for(int i=0;i<n;i++)
    {
        average_all+=all[i];
    }
    for(int i=0;i<man;i++)
    {
        average_man+=m[i];
    }
    for(int i=0;i<woman;i++)
    {
        average_woman+=w[i];
    }
    average_all=average_all/n;average_man=average_man/man;average_woman=average_woman/woman;
    cleardevice();
    setcolor(EGERGB(0x90,0xFF,0xFF));
    line(x,H-x,W-x,H-x);
    line(x,H-x,x,x);
    setcolor(EGERGB(0x0,0xFF,0x0));
    line(x,H-x-average_all*4,W-200,H-x-average_all*4);
    setcolor(EGERGB(0xFF,0x0,0x0));
    line(x,H-30-average_all*4,x+50,H-30-average_all*4+(m[0]-average_man)*4);
    y=H-30-average_all*4+(m[0]-average_man)*4;
    for(int i=1;i<man;i++)
    {
        x+=50;
        line(x,y,x+50,H-30-average_all*4+(m[i]-average_man)*4);
        y=H-30-average_all*4+(m[i]-average_man)*4;
    }
    x=30;
    setcolor(EGERGB(0x0,0x0,0xFF));
    line(x,H-30-average_all*4,x+50,H-30-average_all*4+(w[0]-average_woman)*4);
    y=H-30-average_all*4+(w[0]-average_woman)*4;
    for(int i=1;i<woman;i++)
    {
        x+=50;
        line(x,y,x+50,H-30-average_all*4+(w[i]-average_woman)*4);
        y=H-30-average_all*4+(w[i]-average_woman)*4;
    }
    setcolor(EGERGB(0xff,0xff,0x0));
    setfont(30, 0, "����");
	outtextxy(W/2-150, 10, "VARIANCE CURVE");
	setfont(18, 0, "����");
	setcolor(EGERGB(0x0,0xFF,0x0));
	outtextxy(W-200, 50, "GREEN->AVERAGE");
	setcolor(EGERGB(0xFF,0x0,0x0));
    outtextxy(W-200, 70, "RED  ->MAN");
    setcolor(EGERGB(0x0,0x0,0xFF));
    outtextxy(W-200, 90, "BLUE->WOMAN");
    free_list(a);
    while(1)
    if(getch()==27)
    break;
}

void ege_averagescore(LIST*a)//ͨ��weighted_average����Ӻ����������Ȩƽ���֣�Ȼ���ٰ��������������Ů��ͼ��
{
    read_data(a);
    int n=count_list(a);
    float b[n];
    weighted_average(a,b);
    initgraph(W, H);
    int m=31,w=31;
	setcolor(EGERGB(0xFF,0xFF,0xFF));
    line(m-1,H-1,W-100,H-1);
    line(m-1,H,m-1,H/2+50);
    line(m-1,H/2,W-100,H/2);
    line(m-1,H/2,m-1,50);
    setfont(30, 0, "����");
    outtextxy(m-8, 50, "^");
    outtextxy(m-8, H/2+50, "^");
    setfont(15, 0, "����");
    outtextxy(m+10, 50, "score");
    outtextxy(m+10, H/2+50, "score");
    outtextxy(W-98, H/2-15, ">student");
    outtextxy(W-98, H-1-15, ">student");
    setcolor(EGERGB(0xFF,0xFF,0x0));
	setfont(18, 0, "����");
	outtextxy(W/4*3, H/2+30, "Man");
	outtextxy(W/4*3, 30, "Woman");
	setfont(30, 0, "����");
	outtextxy(W/2-150, 10, "AVERAGE SCORE");
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	for(int i=0;i<n;i++)
	{   if(strcmp(a->next->data.gender,"man")==0)
            {
                setfillcolor(EGERGB(0xFF, 0x0, 0x80));
                bar(m,H-1,m+30,H-(b[i]));setfont(10, 0, "����");xyprintf(m+15,H-20-b[i],a->next->data.name);
                a=a->next;
                m+=50;
            }
        else
        {
                setfillcolor(EGERGB(0x0, 0x0, 0xFF));
                bar(w,H/2,w+30,H/2-(b[i]));setfont(10, 0, "����");xyprintf(w+15,H/2-20-b[i],a->next->data.name);
                a=a->next;
                w+=50;
        }
	}
	free_list(a);
}
void ege_score_choose(LIST*a)//�����û�ѡ��Ŀ�Ŀ������Ӧ����״ͼ
{   cleardevice();
    setcolor(EGERGB(0x0,0xFF,0x0));
    setfont(20,0,"����");
    xyprintf(500,0,"please choose the subject(A:Chinese,B:math,C:English,D:PE,E:Average,Esc:EXIT)");
    int key;char c[10]="Chinese",m[10]="Math",e[10]="English",p[10]="PE";
    for(;key!=key_esc;)
    {
        key=getch();
        switch(key)
        {
            case 65:
            case 97:ege_scoreofsubject(a,c,0);break;;
            case 66:
            case 98:ege_scoreofsubject(a,m,1);break;
            case 67:
            case 99:ege_scoreofsubject(a,e,2);break;
            case 68:
            case 100:ege_scoreofsubject(a,p,3);break;
            case 69:
            case 101:ege_averagescore(a);break;
            default:cleardevice();setfont(30,0,"����");xyprintf(500,100,"Error!\n");break;
        }
    }
    cleardevice();
}
void mysystem(LIST*a)//����̨�µĲ˵�������Ӧ�û�ѡ��
{
    while(1)
    {
      printf("please choose the number of the list\n");
      printf("1.Initial the data\n");
      printf("2.Print the data\n");
      printf("3.Delete some data\n");
      printf("4.Insert some data\n");
      printf("5.Visualized the data\n");
      printf("6.Exit\n");
      setbuf(stdin,NULL);
      int meau=0;
      scanf("%d",&meau);
      switch(meau)
      {
          case 1:setbuf(stdin,NULL);init_imput(a);break;
          case 2:setbuf(stdin,NULL);print_list(a);break;
          case 3:setbuf(stdin,NULL);del(a);break;
          case 4:setbuf(stdin,NULL);ins(a);break;
          case 5:setbuf(stdin,NULL);ege_score_choose(a);break;
          case 6:setbuf(stdin,NULL);printf("YOU HAVE EXITED THE SYSTEM!\n");
                 return;
          default:printf("Error!\n");break;
      }
    }
}
void order(LIST*a);
void my_egesystem(LIST*a)//ege�µĲ˵�����Ӧ�û���������
{
	initgraph(W, H);
    setcaption("DATE OF STUDENT MANAGING SYSTEM");
    read_data(a);
	setfont(18, 0, "����");
	setcolor(EGERGB(0x0,0x90,0xF0));
	while(1)
	{   settextjustify(CENTER_TEXT, TOP_TEXT);
        setfont(30,0,"����");
        cleardevice();
	    xyprintf(500, 0,"Welcome to my egesystem !");
	    xyprintf(500,80,"1.initialize the data ** 2.print the date");
        xyprintf(500,160,"3.delite some data   ** 4.insert some date");
        xyprintf(500,240,"5.visualize the date ** 6.order the list");
        xyprintf(500,320,"7.draw variance curve** 8.find the student");
        xyprintf(400,400,"ESC TO EXIT!");
        int k = 0;
        for ( ; k != key_esc; )
        {
            setfont(30,0,"����");
            xyprintf(500,400,"PLEASE CHOOSE 1~8");
            char str[32];
            k = getch();
            switch(k)
            {
                case 49:init_imput(a);break;
                case 50:cleardevice();ege_print_list(a);break;
                case 51:del(a);break;
                case 52:ins(a);break;
                case 53:ege_score_choose(a);break;
                case 54:order(a);break;
                case 55:variance(a);break;
                case 56:find_data(a);break;
                default:cleardevice();setfont(30,0,"����");xyprintf(500,0,"PRESS THE RIGHT KEY!");break;
            }
        }
        cleardevice();
        setfont(30,0,"����");
        xyprintf(500,0,"YOU HAVE EXIT!");
        xyprintf(500,100,"PREES ANY KEY TO RETURN!");
		xyprintf(500,200,"PREES 'ESC' TO CLOSE!");
        if(int k1=getch()==27)
            break;

	}
	closegraph();
	free_list(a);

}
void get_data(STU *data)//ͨ��intputbox_getline�õ��ַ�������sscanf�������ַ����и�ʽ���ض�ȡ��Ҫ������
{

    char buff[200];//����һ���ַ������飬
    inputbox_getline("PLEASE INPUT:","please imput number,name,gender,orgin place,score(Chinese,math,English,PE)",buff,sizeof(buff));
	sscanf(buff,"%s%s%s%s%d%d%d%d",data->number,data->name,data->gender,data->origin,&data->score[0],&data->score[1],&data->score[2],&data->score[3]);

}
void order(LIST*a)//��4�ſ�Ŀ��Ȩƽ���֣��ۺϳɼ�������������
{
    read_data(a);
    int n=count_list(a);
    float score[n];
    weighted_average(a,score);
    LIST*pf=a->next,*pb=(LIST*)malloc(sizeof(LIST)),tmp;
    for(int i=0;i<n;i++)
    {
        pb=pf->next;
        for(int j=1;j<n-i;j++)
        {
            if(score[j-1]<score[j])
            {
                tmp=*pb;
                *pb=*pf;
                *pf=tmp;
                tmp.next=pf->next;
                pf->next=pb->next;
                pb->next=tmp.next;
            }
            pb=pb->next;
        }
        pf=pf->next;
    }
        free(pb);
    char str1[200],str2[200];int tmp0=30;
    cleardevice();
    sprintf(str1,"number\tname\tgender\tplace\tChinese\tmath\tEnglish\tPE\n");
    setcolor(EGERGB(0x0, 0xFF, 0x0));
    setfont(18,0,"����");
    outtextrect(0,0,W,30,str1);
    LIST*p=a->next;
    while(p!=NULL)
    {
        sprintf(str2,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p->data.number,p->data.name,p->data.gender,p->data.origin,p->data.score[0],p->data.score[1],p->data.score[2],p->data.score[3]);
        outtextrect(0,tmp0,W,tmp0+30,str2);
        tmp0+=30;
        p=p->next;
    }
    free_list(a);
    return;
}

int main()
{
    LIST*head=create_list_head();
    my_egesystem(head);
    free(head);
    return 0;
}

