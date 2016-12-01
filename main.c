#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <gtk/gtk.h>
#endif

#include "sqlite3.h"

enum State{
	None = 1,
};

// 链式堆栈
typedef struct Stack {
	struct Stack *prev;
	enum State state;
}Stack;

int my_gtk_main (int argc, char **argv);
void createwindow(int argc, char**argv);

int main(int argc, char**argv)
{
	sqlite3 *db = NULL;

	int res;

	res = sqlite3_open("test.db", &db);

	if (res != SQLITE_OK) {
		printf("Open db failed\n");
		goto QUIT;
	}

#ifdef _WIN32
	createwindow(argc, argv);
#else
	my_gtk_main(argc, argv);
#endif

QUIT:
	sqlite3_close(db);
	return 0;
}

#ifdef _WIN32
void createwindow(int argc, char**argv)
{
	MessageBox(0, "test messagebox", 0, 0);
}
#else
static void activate (GtkApplication* app,
		gpointer        user_data)
{
	GtkWidget *window;

	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "Window");
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	gtk_widget_show_all (window);
}

int my_gtk_main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}
#endif
