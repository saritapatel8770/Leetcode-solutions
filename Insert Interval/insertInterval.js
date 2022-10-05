function insertInterval(intervals, newInterval) {
    let result = []
    let isFinished = false
    
    for(let i = 0; i < intervals.length; i++) {
        const interval = intervals[i]
        
        if(newInterval[0] > interval[1]) {
            result.push(interval)
        } else if(newInterval[1] < interval[0]) {
            result = result.concat([newInterval], intervals.slice(i))
            isFinished = true
            break;
        } else {
            newInterval[0] = Math.min(newInterval[0], interval[0])
            newInterval[1] = Math.max(newInterval[1], interval[1])
        }
    }
    
    if(!isFinished) result.push(newInterval)
    
    return result
}

/*
  intervals = [[1, 3], [6, 9]]
  newInterval = [2, 5]
  console.log(insertInterval(intervals, newInterval)) // [[1, 5], [6, 9]]
*/
