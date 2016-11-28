# -*- coding:utf-8 -*-
from digraph import *
from queue import Queue

class GraphAlg:
    '''算法导论上的图算法的具体实现类
    '''
    white = 0
    gray = 1
    black = 2
    time = 0

    #------------------------------------------------------------
    @classmethod
    def bfs(cls, G, s):
        '''广度优先搜索,注意是从特定点出发的，所以广度优先搜索不一定访问到
        图中的所有节点，只能访问到该点可到达的节点
        '''
        bfs_visit_oder = []
        color = {}
        d = {}
        pi = {}
        for node in G.nodes():
            color[node] = cls.white
            d[node] = float("inf")
            pi[node] = None
        color[s] = cls.gray
        d[s]    = 0
        Q = Queue( len(G) ) #队列的长度等于图的节点数目，也就是图的长度
        Q.enqueue(s)
        while not Q.is_empty() :
            u = Q.dequeue()
            for eachsucc in G.succ(u):
                if color[eachsucc] == cls.white:
                    color[eachsucc] = cls.gray
                    d[eachsucc] += 1
                    pi[eachsucc] = u
                    Q.enqueue(eachsucc)
            color[u] = cls.black
            bfs_visit_oder.append(u)
        return bfs_visit_oder
    #------------------------------------------------------------
    @classmethod
    def dfs(cls, G, visit_oder = None):
        '''深度优先搜索,默认无序的访问
        visit_oder: a list or tuple, that have the node in graph 
        '''
        color = {} #节点的颜色标记，用于访问控制
        d = {}  #发现时刻
        f = {}  #完成时刻
        pi = {} #父节点
        trees = [] #深度访问森林
        cls.time = 0
        for node in G.nodes():
            color[node] = cls.white
            pi[node] = None
        if not visit_oder:
            for node in G.nodes():
                if color[node] == cls.white:
                    tree = set() #TODO：深度优先访问树,这里首先以集合的形式表述
                    cls.dfs_visit(G, node, color, d, f, pi, tree)
                    trees.append(tree)
        else: #指定顺序的访问
            for node in visit_oder:
                if color[node] == cls.white:
                    tree = set()
                    cls.dfs_visit(G, node ,color, d, f, pi, tree)
                    trees.append(tree)
        cls.time = 0
        return d, f, pi, trees
    

    @classmethod
    def dfs_visit(cls, G, node, color, d, f, pi, tree):
        tree.add(node)
        color[node] = cls.gray
        cls.time += 1
        d[node] = cls.time
        for succnode in G.succ(node):
            if color[succnode] == cls.white:
                pi[succnode] = node
                cls.dfs_visit( G, succnode, color, d, f, pi, tree)
        color[node] = cls.black
        cls.time = cls.time + 1
        f[node] = cls.time
        return None
    #------------------------------------------------------------
    @classmethod
    def strongly_connected_components(cls, G):
        '''
        page553,求强连通分量
        '''
        d, f, pi, trees = cls.dfs(G)
        # 按照完成时间对node进行插入排序
        nodes = f.keys()
        for i in range(1, len(nodes)):
            key = f[ nodes[i] ]
            tmp = nodes[i]
            j = i-1
            while( j>=0 and f[nodes[j]] < key ):
                nodes[j+1] = nodes[j]
                j -= 1
            nodes[j+1] = tmp
        # 图的反转
        gt = G.anoted()
        # 对反转图进行，一定顺序的深度优先访问
        nd, nf, npi, trees2 = cls.dfs(gt, nodes)
        # 得出每一个深度优先访问树，树的节点，构成一个强连通分量
        sccs = trees2
        return sccs

    @classmethod
    def anoted(cls, G):
        '''得到一个图G的转置
        '''
        aG = G.__class__()
        for node in G.nodes():
            for succ in G.succ(node):
                aG.add_edge(succ, node)
        return aG

def __test(edges):
    if not edges:
        print "Empty Edge list"
        return False
    g = DiGraph()
    g.add_edges_from(edges)
    print u"邻接表如下："
    for node, succs in g.adj.iteritems():
        print "%s %s" %(str(node), str(succs))

    bfs_order = GraphAlg.bfs(g, g.adj.keys()[0])
    print u"%s 为源节点的广度优先访问顺序如下" % g.adj.keys()[0]
    print bfs_order
    
    d, f, pi, dfs_trees = GraphAlg.dfs(g)
    print u"深度优先访问森林如下："
    print dfs_trees

    sccs = GraphAlg.strongly_connected_components(g)
    print u"强连通分量如下"
    print sccs

if __name__ == "__main__":

    edges = [('u','v'), ('u','x'), ('v', 'y'), ('w','y'), \
         ('w','z'), ('x','v'), ('y','x'), ('z','z') ]
    assert __test(edges)
    
    edges2 = [
              ('v','w'), ('s','v'), ('w','s'), ('q','s'),\
              ('q','w'), ('q','t'), ('t','x'), ('t','y'),\
              ('x','z'), ('z','x'), ('y','q'), ('r','y'),\
              ('r','u'), ('u','y')
             ]
    assert __test(edges2)

