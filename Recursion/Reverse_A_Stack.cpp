    void insert(stack<int> &st, int el){
        // Base Condition
        if(st.size() == 0){
            st.push(el);
            return ;
        }
        
        int temp = st.top();
        st.pop();
      
        // Hypothesis
        insert(st, el);
        
        // Induction
        st.push(temp);
        return;
    }

    void Reverse(stack<int> &st){
        // Base Condition
        if(st.size() == 1) return ;
        
        int temp = st.top();
        st.pop();
      
        // Hypothesis
        Reverse(st);
        
        // Induction
        insert(st, temp);
        return;
    }
