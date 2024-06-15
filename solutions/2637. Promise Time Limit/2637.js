/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {
  return async function (...args) {
    return new Promise((resolve, reject) => {
      // 創建一個計時器，在 t 毫秒後拒絕 Promise
      const timeout = setTimeout(() => {
        clearTimeout(timeout); // 清除計時器，以避免重複觸發
        reject("Time Limit Exceeded");
      }, t);

      // 執行非同步函數 fn
      fn(...args)
        .then((result) => {
          clearTimeout(timeout); // 清除計時器，因為函數已經成功完成
          resolve(result); // 解決 Promise，將 fn 的結果傳遞給 resolve
        })
        .catch((error) => {
          clearTimeout(timeout); // 清除計時器，以避免重複觸發
          reject(error); // 函數出現錯誤，拒絕 Promise，將錯誤信息傳遞給 reject
        });
    });
  };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
