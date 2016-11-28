# -*- coding:utf-8 -*-

class DiGraph(object):
    """description of class"""
    def __init__(self):
        self.adj = {} #以字典的形式来表示邻接表，key: node, value: succ nodes list

    def add_node(self, node):
        if self.adj.has_key(node):
            return None
        else:
            self.adj[node] = []

    def add_edge(self, s_node, t_node):
        if not self.adj.has_key(s_node):
            self.adj[s_node] = []
        if not self.adj.has_key(t_node):
            self.adj[t_node] = []
        s_neighbor = self.adj[s_node]
        if t_node not in s_neighbor:
           s_neighbor.append(t_node)
        return None

    def add_edges_from(self, edge_list):
        for edge in edge_list:
            assert len(edge) >= 2, "edge has %d mem" % len(edge)
            if len(edge) > 2:
                print "Warning: property not added"
            self.add_edge(edge[0], edge[1])

    def nodes(self):
        node_list = []
        for node in self.adj.keys():
            node_list.append(node)
        return node_list
    
    def succ(self, node):
        if not self.adj.has_key(node):
            raise Exception, "graph has no node:%s" % str(node)
        return self.adj[node]
    
    def anoted(self):
        aG = self.__class__()
        for node in self.nodes():
            for succ in self.succ(node):
                aG.add_edge(succ, node)
        return aG

    def __str__(self):
        graph_str = "Adj List of Graph:\n"
        for node, adj in self.adj.iteritems():
            graph_str += str(node)+":"+str(adj)+"\n"
        return graph_str

    def __len__(self):
        return len(self.adj)

if __name__ == "__main__":
    g = DiGraph()
    for i in range(0, 10):
        g.add_node(i)
        g.add_edge(i, i+1)
    x = [(1,2,"edge12"), (2,5, 19)]
    g.add_edges_from(x)
    print g
