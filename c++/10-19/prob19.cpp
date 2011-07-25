/* URL: http://projecteuler.net/index.php?section=problems&id=19

You are given the following information, but you may prefer to do some research for yourself.

  - 1 Jan 1900 was a Monday.
  - Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
  - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer: 171 */

#include <iostream>
using namespace std;

int day, month, year;

void setStartDate(int startDay, int startMonth, int startYear) {
	day = startDay;
	month = startMonth;
	year = startYear;
}

bool isLeapYear() {
	if(year % 100 == 0) {	//if century
		if(year % 400 == 0)	//if divisible by 400
			return true;
		else
			return false;
	} else if(year % 4 == 0)//else if divisible by 4
		return true;
	else
		return false;
}

int daysInMonth() {
	if(month == 2) {
		if(isLeapYear())
			return 29;
		else
			return 28;
	} else if((month == 4) || (month == 6) || (month == 9) || (month == 11))
		return 30;
	else
		return 31;
}

/*Variable 'numDays' must not be greater than 27*/
void updateDate(int numDays) {
	day += numDays;
	if(day > daysInMonth()) {
		day -= daysInMonth();
		month++;
	}
	if(month > 12) {
		month = 1;
		year++;
	}
}

/*Global variable 'day' must be set to a Sunday*/
int sundaysOnFirst(int endYear) {
	int sundays = 0;
	for(; year <= endYear; updateDate(7)) {
		if(day == 1)
			sundays++;
	}
	return sundays;
}

int main() {
	setStartDate(6, 1, 1901);
	cout << sundaysOnFirst(2000) << endl;
    return 0;
}
