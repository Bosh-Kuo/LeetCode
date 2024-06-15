var TimeLimitedCache = function () {
  this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  const currentTime = Date.now();
  const expirationTime = currentTime + duration;

  if (this.cache.has(key)) {
    const { expiration } = this.cache.get(key);
    if (expiration > currentTime) {
      // 如果鍵已存在且未過期，更新值和過期時間
      this.cache.set(key, { value, expiration: expirationTime });
      return true;
    }
  }

  // 如果鍵不存在或已過期，設置新的鍵值對
  this.cache.set(key, { value, expiration: expirationTime });
  return false;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  const currentTime = Date.now();
  if (this.cache.has(key)) {
    const { value, expiration } = this.cache.get(key);
    if (expiration > currentTime) {
      // 如果鍵存在且未過期，返回值
      return value;
    } else {
      // 如果鍵存在但已過期，刪除鍵並返回 -1
      this.cache.delete(key);
    }
  }
  return -1; // 如果鍵不存在或已過期，返回 -1
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  const currentTime = Date.now();
  let count = 0;
  this.cache.forEach((entry) => {
    if (entry.expiration > currentTime) {
      count++;
    }
  });
  return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
