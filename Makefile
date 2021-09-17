OBJS = lunt_kase_assn3.o lunt_reminder.o lunt_appointment.o lunt_day.o lunt_calendar.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = Calendar_EXE

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

lunt_kase_assn3.o: lunt_calendar.h lunt_reminder.h lunt_appointment.h lunt_day.h lunt_kase_assn3.cpp
	$(CC) $(CFLAGS) lunt_kase_assn3.cpp

lunt_reminder.o: lunt_reminder.h lunt_reminder.cpp
	$(CC) $(CFLAGS) lunt_reminder.cpp

lunt_appointment.o: lunt_appointment.h lunt_reminder.h lunt_appointment.cpp
	$(CC) $(CFLAGS) lunt_appointment.cpp

lunt_day.o: lunt_day.h lunt_reminder.h lunt_appointment.h lunt_day.cpp
	$(CC) $(CFLAGS) lunt_day.cpp

lunt_calendar.o: lunt_calendar.h lunt_day.h lunt_reminder.h lunt_appointment.h lunt_calendar.cpp
	$(CC) $(CFLAGS) lunt_calendar.cpp

clean:
	rm -v *.o *~
