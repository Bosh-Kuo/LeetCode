/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  let hashTable = {};
  return function (...args) {
    const key = args.toString();
    if (key in hashTable) return hashTable[key];
    else {
      hashTable[key] = fn(...args);
      return hashTable[key];
    }
  };
}

/**
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1
 */
