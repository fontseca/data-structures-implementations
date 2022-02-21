const { outOfRange: { greater, lower} } = require('../errors/errs.js');

function removeAt(position = 0) {
  if (position >= this.size) throw new Error(greater);
  if (position < 0) throw new Error(lower);

  let currentNode = this.head;
  
  if (position == 0) {
    this.head = currentNode.next;
    this.size--;
    return true;
  }
  
  let nodeToDelete = currentNode;

  for (let i = 0; i <= (position - 1); ++i) {
    currentNode = nodeToDelete;
    nodeToDelete = nodeToDelete.next;
  }

  currentNode.next = nodeToDelete.next;
  nodeToDelete.next = null;
  nodeToDelete = null;
  this.size--;
}

module.exports = removeAt;