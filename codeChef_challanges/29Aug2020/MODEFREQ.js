process.stdin.resume();
process.stdin.setEncoding("utf8");

let input = "";
process.stdin.on("data", function (chunk) {
  input += chunk;
});

process.stdin.on("end", function () {
  const arr = input.split("\n");
  let i = 0;
  let v = 1;
  let testCases = parseInt(arr[0]);
  while (testCases) {
    const n = parseInt(arr[v]);
    const values = arr[v + 1].split(" ").map((x) => +x);
    v += 2;
    const freq = {};
    values.forEach((el) => {
      if (!freq[el]) {
        freq[el] = 1;
      } else {
        freq[el]++;
      }
    });

    const ff = Object.keys(freq).map((keys) => freq[keys]);
    const repFreq = {};
    ff.forEach((el) => {
      if (!repFreq[el]) {
        repFreq[el] = 1;
      } else {
        repFreq[el]++;
      }
    });
    const highestFreq = [];
    let h = 0;
    Object.keys(repFreq).forEach((key) => {
      if (repFreq[key] >= h) {
        h = repFreq[key];
      }
    });
    Object.keys(repFreq).forEach((key) => {
      if (repFreq[key] == h) {
        highestFreq.push(+key);
      }
    });

    console.log(highestFreq.sort()[0]);
    testCases--;
  }
});
