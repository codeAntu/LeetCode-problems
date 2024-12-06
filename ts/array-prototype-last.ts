interface Array<T> {
  last(): T | -1;
}

Array.prototype.last = function () {
  return this.length ? this[this.length - 1] : -1;
};
