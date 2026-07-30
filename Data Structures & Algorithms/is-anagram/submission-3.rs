use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
     
        let mut vote_count: HashMap<char,i32> = HashMap::new();
        let mut sum = 0;
        for letter in s.chars(){
            match vote_count.get(&letter) {
                Some(count) => {
                    vote_count.insert(letter, count+1);
                }
                None => {
                    vote_count.insert(letter,1);
                }
           }

         }

         for letter in t.chars(){
            match vote_count.get(&letter){
                Some(count) => {
                    vote_count.insert(letter,count-1);

                    if vote_count.get(&letter).copied().unwrap_or(0)< 0 {
                        return false;
                    }
                }
                None => {
                    return false;
                }
            }
         }

        for (key,val) in &vote_count {
            sum += val;
        }
        if sum != 0 {
            return false;
        }
         return true;
    }
}
