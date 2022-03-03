function BinarySearchTree() {
  const max = (a, b) => a >= b ? a : b;
  let root = null;

  function TreeNode(key = null, data = {}) {
    this.data = data;
    this.key = key;
    this.left = null;
    this.right = null;
    this.parent = null;
  }

  function insert(key, data) {
    let y = null;
    let x = root;
    let z = new TreeNode(key, data);

    while (x !== null) {
      y = x;
      x = (z.key < x.key) ? x.left : x.right;
    }
    z.parent = y;
    if (y == null)
      root = z; /* tree was empty */
    else if (z.key < y.key)
      y.left = z;
    else
      y.right = z;
  }

  function inorderTraversal(x = root, tmpSet = new Set()) {
    if (x !== null) {
      this.inorderTraversal(x.left, tmpSet);
      tmpSet.add(x.key);
      this.inorderTraversal(x.right, tmpSet);
    }
    return tmpSet;
  }

  function search(key, x = root) {
    if (x === null || key === x.key)
      return x;
    if (key < x.key)
      return search(key, x.left);
    else return search(key, x.right);
  }

  function minimun(x = root) {
    if (x.left !== null)
      return minimun(x.left);
    return x;
  }

  function maximun(x = root) {
    if (x.right !== null)
      return maximun(x.right);
    return x;
  }

  function height(x = root) {
    if (x === null) return -1;
    return max(height(x.left), height(x.right)) + 1;
  }

  this.insert = insert;
  this.inorderTraversal = inorderTraversal;
  this.search = search;
  this.minimun = minimun;
  this.maximun = maximun;
  // this.preorderTraversal = preorderTraversal;
  this.height = height;
}

console.clear();
var tr = new BinarySearchTree();