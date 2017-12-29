#include "types.h"
#include "user.h"
#include "date.h"

static char *months[] = {"NULL", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
static char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int dayofweek (int y, int m, int d)
{
	return (d += m < 3 ? y--:y-2, 23*m / 9 + d + 4 + y / 4 - y / 100 + y / 400)%7;
}


int main(int argc, char *argv[])
{
	int day;
	struct rtcdate r;

	if (date(&r))
	{
		printf(2, "date failed\n");
		exit();
	}

	day = dayofweek(r.year, r.month, r.day);

	printf(1, "%s %s %d", days[day], months[r.month], r.day);
	printf(1, " %d:%d:%d CST %d\n", r.hour + 8, r.minute, r.second, r.year);

	exit();
}
