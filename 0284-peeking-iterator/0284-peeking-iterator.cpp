class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasElement;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasElement = Iterator::hasNext();

        if (hasElement)
            nextElement = Iterator::next();
    }

    int peek() {
        return nextElement;
    }

    int next() {
        int current = nextElement;

        hasElement = Iterator::hasNext();

        if (hasElement)
            nextElement = Iterator::next();

        return current;
    }

    bool hasNext() const {
        return hasElement;
    }
};