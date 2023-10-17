/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
  const flattenArr = [];
  if (n === 0) return arr;
  arr.forEach((item) => {
    if (Array.isArray(item) && n > 0) flattenArr.push(...flat(item, n - 1));
    else if (!Array.isArray(item)) flattenArr.push(item);
  });
  return flattenArr;
};
