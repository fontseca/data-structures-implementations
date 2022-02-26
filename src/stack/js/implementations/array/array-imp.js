function Stack() {
  let _items = [];
  let _size = 0;

  this.empty = function empty() {
    return !_size ? true : false;
  }

  this.push = function push(data) {
    _items[_size++] = data;
  };

  this.pop = function pop() {
    if (this.empty())
      throw Error('stack underflow');
    _size--;
    return _items.pop();
  };

  this.peek = function peek() {
    return _items[_size - 1];
  };

  this.size = function size() {
    return _size;
  }

  this.clear = function clear() {
    _items = [];
    _size = 0;
  }
}