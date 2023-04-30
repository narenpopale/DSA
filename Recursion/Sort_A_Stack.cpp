    public void insert(Stack<Integer> s,int val){
        // Base Condition
        if(s.size() == 0 || s.peek() < val){
            s.push(val);
            return;
        }
        
        int temp = s.peek();
        s.pop();
        
        // Hypothesis
        insert(s, val);
        
        // Induction
        s.push(temp);
        return;
    }
    
    public void solve(Stack<Integer> s){
        // Base Condition
        if(s.size() == 1) return;
		
        int temp = s.peek();
        s.pop();
        
        // Hypothesis
        sort(s);
        
        // Induction
        insert(s, temp);
        return;
    }
    
    public Stack<Integer> sort(Stack<Integer> s){
    
        solve(s);

        return s;
    } 
