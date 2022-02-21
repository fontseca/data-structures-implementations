const Node = require('../../node/Node');

function insertAtStart(data) {
  this.head = new  Node(data, this.head);
  this.size++;
  return true;
}

module.exports = insertAtStart;