const Node = require('../../node/Node');

function insertAtEnd(data) {
  let newNode = new Node(data, null);
  let tempNode = this.head;
  let currentNode = tempNode;

  if (!this.size) {
    this.head = newNode;
    this.size++;
    return true;
  }

  while (tempNode != null) {
    currentNode = tempNode;
    tempNode = tempNode.next;
  }

  currentNode.next = newNode;
  newNode.next = null;

  this.size++;
  return true;
}

module.exports = insertAtEnd;