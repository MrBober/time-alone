#include <stdio.h>
#include <unistd.h>
#include <glib/gprintf.h>
#include <libnotify/notify.h>

int main()
{
	int i = 0;
	while(1)
	{
		i++;
		sleep(1);
		notify_init ("Another second of being alone!");

		char *string;
		if (i == 1)
			string = g_strdup_printf("%d second has passed.", i);
		else
			string = g_strdup_printf("%d seconds have passed.", i);

		NotifyNotification *life = notify_notification_new("Another second of being alone!", string, NULL);
		notify_notification_set_urgency (life, NOTIFY_URGENCY_CRITICAL);

		notify_notification_show (life, NULL);

		g_object_unref(G_OBJECT(life));
		notify_uninit();
	}
	return 0;
}
