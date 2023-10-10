/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
  return new Promise((resolve, reject) => {
    let resolvedCount = 0;
    let results = [];
    if (!functions.length) resolve(results);

    functions.forEach((asyncFunction, i) => {
      asyncFunction()
        .then((response) => {
          results[i] = response;
          resolvedCount++;
          if (resolvedCount === functions.length) resolve(results);
        })
        .catch((error) => reject(error));
    });
  });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
