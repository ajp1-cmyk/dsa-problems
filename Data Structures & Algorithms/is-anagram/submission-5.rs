use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
     
        let mut vote_count: HashMap<char,i32> = HashMap::new();

         for letter in s.chars(){
            *vote_count.entry(letter).or_insert(0) +=1;
         }

        for letter in t.chars(){

            if let Some(count) = vote_count.get_mut(&letter) {
                *count -=1;
                if *count < 0 {
                    return false;
                }
            }else{
                return false;
            }
        }

      vote_count.values().all(|&count| count == 0)
    }
}
