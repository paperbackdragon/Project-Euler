#include<iostream>
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
