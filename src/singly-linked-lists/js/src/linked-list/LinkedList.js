const {
  insertAtStart,
  entries,
  insertAt,
  insertAtEnd,
  elementAt,
  removeAt,
  clear,
  reverse
} = require('./operations/index.js');

function LinkedList() {
  this.head = null;
  this.size = 0;
};

LinkedList.prototype = {
  insertAtStart,
  entries,
  insertAt,
  insertAtEnd,
  elementAt,
  removeAt,
  clear,
  reverse
};

module.exports = LinkedList;