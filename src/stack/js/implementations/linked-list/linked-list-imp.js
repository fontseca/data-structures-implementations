function Stack() {
  const StackNode = function StackNode(data) {
    this.data = data;
    this.next = null;
  }
  let _placeholder = new StackNode(null);
  let _size = 0;

  this.push = function push(data) {
    let newNode = new StackNode(data);
    newNode.next = _placeholder.next;
    _placeholder.next = newNode;
    _size++;
  }

  this.peek = function pop() {
    if (this.empty()) return null;
    return _placeholder.next.data;
  }

  this.pop = function pop() {
    if (this.empty()) throw Error('stack underflow');
    let tmpNode = _placeholder.next;
    let tmpData = tmpNode.data;
    _placeholder.next = tmpNode.next;
    tmpNode = null;
    _size--;
    return tmpData;
  }

  this.clear = function clear() {
    _placeholder.next = null;
    _size = 0;
  }
  
  this.size = function size() {
    return _size;
  }

  this.empty = function empty() {
    return _placeholder.next == null;
  }
}