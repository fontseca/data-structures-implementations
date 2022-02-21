function reverse() {
  let current = this.head;
  let prev = null;
  let next = {};

  while (current != null) {
    next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  this.head = prev;
  return true;
}

module.exports = reverse;