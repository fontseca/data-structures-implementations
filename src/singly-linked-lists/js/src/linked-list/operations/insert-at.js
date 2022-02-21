const Node = require('../../node/Node');
const { outOfRange: { greater, lower} } = require('../errors/errs.js');

function insertAt(position = 0, data) {
  if (position == 0) return this.insertAtStart(data);
  if (position >= this.size) throw new Error(greater);
  if (position < 0) throw new Error(lower);

  let newNode = new Node(data, null);
  let tempNode = this.head;

  for (let i = 0; i <= position - 2; ++i)
    tempNode = tempNode.next;
  
  newNode.next = tempNode.next;
  tempNode.next = newNode;
  this.size++;
  
  return true;
}

module.exports = insertAt;