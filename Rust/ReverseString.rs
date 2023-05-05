impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let vectorLength = s.len();
        for index in 0..vectorLength/2
        {
            let mut temp = s[index];
            s[index] = s[vectorLength-index-1];
            s[vectorLength-index-1] = temp;
        }
    }
}
