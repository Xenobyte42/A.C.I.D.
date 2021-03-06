#ifndef ACID_INCLUDE_I_OBSERVABLE_H_
#define ACID_INCLUDE_I_OBSERVABLE_H_

#include <list>

#include <i_observer.h>

template <class T>
class IObservable {
  public:
	~IObservable() = default;

	void add_observer(IObserver<T>* observer) {
		observers.push_front(observer);
	}
	void delete_observer(IObserver<T>* observer) {
		observers.remove(observer);
	}

  protected:
    std::list<IObserver<T>*> observers;
};

#endif  // ACID_INCLUDE_I_OBSERVABLE_H_
