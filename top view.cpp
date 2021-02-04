void topView(Node * root) {
        queue<pair<int,Node*>> q; q.push(make_pair(0,root));
        map<int,Node*> ans;
        for(auto i=q.front();!q.empty();q.pop(),i=q.front()){
            if(!i.second) continue;
            ans.insert(i);
            q.push(make_pair(i.first+1,i.second->right));
            q.push(make_pair(i.first-1,i.second->left));
        }
        for(auto i:ans) cout<<i.second->data<<" ";

    }
