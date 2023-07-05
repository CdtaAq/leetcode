import React, { useState } from 'react';

const SortingAlgorithm = () => {
  const [array, setArray] = useState([6, 4, 9, 2, 7, 1]);

  const bubbleSort = () => {
    const arr = [...array];
    const n = arr.length;

    for (let i = 0; i < n - 1; i++) {
      for (let j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          // Swap elements
          const temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    setArray(arr);
  };

  return (
    <div>
      <button onClick={bubbleSort}>Sort</button>
      <ul>
        {array.map((item, index) => (
          <li key={index}>{item}</li>
        ))}
      </ul>
    </div>
  );
};

export default SortingAlgorithm;
