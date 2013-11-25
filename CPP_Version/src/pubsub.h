#ifndef PUBSUB_H
#define PUBSUB_H

#include <list>

using namespace std;
class Publisher;

class Subscriber{
public:
	virtual ~Subscriber() {}
	virtual void update(Publisher* who, void* what = 0) = 0;
};

class Publisher{
public:
	Publisher() {notifyEnabled = true;}
	virtual ~Publisher() {}
	void subscriber(Subscriber *s) { subscribers.push_back(s); }
	void unsubscribe(Subscriber *s) { subscribers.remove(s); }
	void notify(void *what = 0, Subscriber *s = 0);
	void setNotifyEnabled(bool flag) { notifyEnabled = flag; }
	bool getNotifyEnabled() const { return notifyEnabled; }\
private:
	list<Subscriber*> subscribers;
	bool notifyEnabled;
};


#endif
