#include <gtk/gtk.h>

GtkWidget *board[9][9],*window,*label;
int sudoku[9][9]={{-3, 0, -6, -5, 0, -8, -4, 0, 0},  
                      {-5, -2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, -8, -7, 0, 0, 0, 0, -3, -1},  
                      {0, 0, -3, 0, -1, 0, 0, -8, 0},  
                      {-9, 0, 0, -8, -6, -3, 0, 0, -5},  
                      {0, -5, 0, 0, -9, 0, -6, 0, 0},  
                      {-1, -3, 0, 0, 0, 0, -2, -5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, -7, -4},  
                      {0, 0, -5, -2, -0, -6, -3, 0, 0}};


bool isSafe(int sudoku[9][9])
{
	
	for(int i=0;i<9;i++)
	{
		//checking row
		int x[10]={0};
		for(int j=0;j<9;j++)
		{
			x[abs(sudoku[i][j])]++;
		}
		for(int j=1;j<10;j++)
		{
			if(x[j]>1)
			{
				return false;
			}
			x[j]=0;
		}

		//checking cloumn
		for(int j=0;j<9;j++)
		{
			x[abs(sudoku[i][j])]++;
		}
		for(int j=1;j<10;j++)
		{
			if(x[j]>1)
			{
				return false;
			}
			x[j]=0;
		}
		
		if(i%3==0)
		{
			int p=0;
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					x[abs(sudoku[i][p+k])]++;
				}
				
				for(int k=0;k<3;k++)
				{
					x[abs(sudoku[i+1][p+k])]++;
				}

				for(int k=0;k<3;k++)
				{
					x[abs(sudoku[i+2][p+k])]++;
				}
				for(int j=1;j<10;j++)
				{
					if(x[j]>1)
					{
						return false;
					}
					x[j]=0;
				}
				p=p+3;
			}
						
		}
	}
	return true;
}


static void click(GtkWidget *widget,gpointer data)
{
	int arr[2];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(widget==board[i][j])
			{
				arr[0]=i;
				arr[1]=j;
				break;
			}
		}
	}
	int i=arr[0],j=arr[1];
	gchar text=*gtk_button_get_label(GTK_BUTTON(widget));
	int a=text;
	a=a-'0';
	a=a%9+1;

	char ch[2];
	ch[0]=a+'0';
	ch[1]='\0';
	//g_print(ch);
	gtk_button_set_label(GTK_BUTTON(board[i][j]),ch);

	sudoku[i][j]=a;
	if(!isSafe(sudoku))
   	{
		gtk_label_set_text(GTK_LABEL(label),"Alert: Wrong!!");
	}
	else
	{
		int flag=1;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(sudoku[i][j]==0)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			gtk_label_set_text(GTK_LABEL(label),"CONGRATULATION!!");	
		else
			gtk_label_set_text(GTK_LABEL(label),"");	
	}
}



int main(int argc,char *argv[])
{
	
	gtk_init(&argc,&argv);
	GtkWidget *vbox,*hbox,*separator;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,200,300);
	gtk_window_set_title(GTK_WINDOW(window),"SUDOKU");
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	hbox=gtk_hbox_new(0,0);
	vbox=gtk_vbox_new(0,0);
	label=gtk_label_new("");

	for(int i=0;i<9;i++)
	{
		hbox=gtk_hbox_new(0,0);
		for(int j=0;j<9;j++)
		{
				if(sudoku[i][j]==-1)
					board[i][j]=gtk_button_new_with_label("1");
				else if(sudoku[i][j]==-2)
					board[i][j]=gtk_button_new_with_label("2");
				else if(sudoku[i][j]==-3)
					board[i][j]=gtk_button_new_with_label("3");
				else if(sudoku[i][j]==-4)
					board[i][j]=gtk_button_new_with_label("4");
				else if(sudoku[i][j]==-5)
					board[i][j]=gtk_button_new_with_label("5");
				else if(sudoku[i][j]==-6)
					board[i][j]=gtk_button_new_with_label("6");
				else if(sudoku[i][j]==-7)
					board[i][j]=gtk_button_new_with_label("7");
				else if(sudoku[i][j]==-8)
					board[i][j]=gtk_button_new_with_label("8");
				else if(sudoku[i][j]==-9)
					board[i][j]=gtk_button_new_with_label("9");
				else
					board[i][j]=gtk_button_new_with_label("0");	

			gtk_widget_set_size_request(board[i][j],20,20);
            gtk_box_pack_start(GTK_BOX(hbox),board[i][j],0,0,0);
            if((j+1)%3==0)
            {
                separator=gtk_vseparator_new();
                gtk_box_pack_start(GTK_BOX(hbox),separator,0,0,0);
            }
		}

        gtk_box_pack_start(GTK_BOX(vbox),hbox,0,0,0);
        if((i+1)%3==0)
        {
            separator=gtk_hseparator_new();
            gtk_box_pack_start(GTK_BOX(vbox),separator,0,0,0);
        }
	}
	
	gtk_box_pack_start(GTK_BOX(vbox),label,0,0,0);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(sudoku[i][j]==0)
			g_signal_connect(board[i][j],"clicked",G_CALLBACK(click),NULL);
		}
	}

	gtk_container_add(GTK_CONTAINER(window),vbox);
    gtk_widget_show_all(window);
    gtk_main();
	return 0;
}
