#include <iostream>
export module a_array;

export template <typename T, int capacity>
class A_Array {
public:
	constexpr A_Array() :pos(-1), size(0) {}

	template<typename ...Args>
	constexpr A_Array(Args... args) : arr{ args... } {
		size = sizeof...(args);
		pos = size - 1;
	}

	constexpr A_Array(const A_Array<T, capacity>& ob) {
		size = ob.size;
		for (int i = 0; i < capacity; i++) {
			arr[i] = ob.arr[i];
		}
	}

	constexpr A_Array(A_Array<T, capacity>&& ob)noexcept {
		size = ob.size;
		for (int i = 0; i < capacity; i++) {
			arr[i] = ob.arr[i];
		}
		ob.clearAll();
	}

	constexpr void operator =(const A_Array<T, capacity>& ob) {
		size = ob.size;
		for (int i = 0; i < capacity; i++) {
			arr[i] = ob.arr[i];
		}
	}

	constexpr void operator =(A_Array<T, capacity>&& ob)noexcept {
		size = ob.size;
		for (int i = 0; i < capacity; i++) {
			arr[i] = ob.arr[i];
		}
		ob.clearAll();
	}

	constexpr int Capacity()const { return capacity; }

	constexpr int Size()const { return size; }

	constexpr void setSize(int size) {
		if (size >= 0)
			this->size = size;
		else
			throw "you can't set negative size";
	}

	constexpr int getCurrentPos()const { return pos; }

	constexpr void setCurrentPos(int pos) {
		if (pos >= 0)
			this->pos = pos;
		else
			throw "you can't set negative position";
	}

	constexpr bool isFull()const { return size == capacity; }

	constexpr bool isEmpty()const { return size == 0; }

	constexpr T getAt(int pos)const {
		if (pos < size && pos >= 0)
			return arr[pos];
		else
			throw "Out of bound read exception";
	}

	constexpr T& At(int pos) {
		if (pos < size && pos >= 0)
			return arr[pos];
		else
			throw "Out of bound read exception";
	}

	constexpr const T* data_const()const { return arr; }

	constexpr T* data() { return arr; }

	constexpr void setAt(T val, int pos) {
		if (pos < size && pos >= 0)
			arr[pos] = val;
		else
			throw "Out of bound write exception";
	}

	constexpr void pushBack(T val) {
		if (size < capacity) {
			size++;
			pos = size - 1;
			arr[pos] = val;
		}
		else
			throw "List is full";
	}

	template <typename ..._Args>
	constexpr void emplaceBack(_Args&&...args) {
		if (size < capacity) {
			size++;
			pos = size - 1;
			arr[pos] = T(std::forward<_Args>(args)...);
		}
		else
			throw "List is full";
	}

	constexpr void pushFront(T val) {
		if (size < capacity) {
			for (int i = size - 1; i >= 0; i--) {
				arr[i + 1] = arr[i];
			}
			size++;
			pos = size - 1;
			arr[0] = val;
		}
		else
			throw "List is full";
	}

	constexpr T pullFromBack() {
		if (size > 0) {
			size--;
			pos = size - 1;
			return arr[pos + 1];
		}
		else
			throw "List is empty";
	}

	constexpr T pullFromFront() {
		if (size > 0) {
			T val = arr[0];
			for (int i = 0; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
			pos = size - 1;
			return val;
		}
		else
			throw "List is empty";
	}

	constexpr void insertAt(T val, int pos) {
		if (pos >= 0 && pos < size && size < capacity) {
			for (int i = size; i > pos; i--) {
				arr[i] = arr[i - 1];
			}
			arr[pos] = val;
			size++;
			pos = size - 1;
		}
		else
			throw "Out of bound write exception or Full";
	}

	constexpr T pullFrom(int pos) {
		if (pos >= 0 && pos < size) {
			T val = arr[pos];
			for (int i = pos; i < size - 1; i++) {
				arr[i] = arr[i + 1];
			}
			size--;
			pos = size - 1;
			return val;
		}
		else
			throw "Out of bound read exception";
	}

	constexpr void clearAll() {
		size = 0;
		pos = -1;
	}

	constexpr T accumulate()const {
		T sum{};
		for (int i = 0; i < size; i++)
			sum += arr[i];
		return sum;
	}

	using arr_ref_type = T(&)[capacity];
	//it returns a ref to the array with full capacity
	constexpr operator arr_ref_type() {
		return arr;
	}

	//it returns a ref to the array with full capacity
	constexpr T(&operator() ())[capacity] { return arr; }

		constexpr T& operator[](int pos) {
		if (pos < size && pos >= 0)
			return arr[pos];
		else
			throw "Out of bound exception";
	}

private:
	int pos;
	int size;
	T arr[capacity];
};