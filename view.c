#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
//  while(1){
  int i,j;
  char a[20]; //time
  char b[20]; //weather
  char c[20]; //hahah
  for(i=0; i != 21; i++)
	a[i]='\0';
  for(i=0; i != 21; i++)
	b[i]='\0';
  for(i=0; i != 21; i++)
	c[i]='\0';
  FILE *ti = fopen("time", "rt");
  FILE *we = fopen("weather", "rt");
  FILE *ha = fopen("hahah", "rt");
  for(i=0; (j=fgetc(ti))!=','; i++)
	a[i]=j;
  for(i=0; (j=fgetc(we))!=','; i++)
	b[i]=j;
  for(i=0; (j=fgetc(ha))!=','; i++)
	c[i]=j;

  GtkWidget *window;
  GtkWidget *view;

  GtkWidget *time;
  GtkWidget *weather;
  GtkWidget *hahah;
	
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 250);
  gtk_window_set_title(GTK_WINDOW(window), "view");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  view = gtk_vbox_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), view);

  time = gtk_button_new_with_label(a);
  weather = gtk_button_new_with_label(b);
  hahah = gtk_button_new_with_label(c);


  gtk_box_pack_start(GTK_BOX(view), time, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(view), weather, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(view), hahah, TRUE, TRUE, 0);
  

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);
  fclose(ti);
  fclose(we);
  fclose(ha);

  gtk_main();
 // sleep(1);
 // }
  return 0;
}
