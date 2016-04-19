# -*- coding: utf-8 -*- #
def read_input():
	'''读取文件里面的每一个数字，将其存储到结构数据中
	'''
	fobj = open("A-sample.in",'r')
	T = int(fobj.readline())
	print "T:%d" % T
	Tcase = []
	for i in range(1,T+1):
		Tcasei = [(),{},[]] # (N,M,K),{(x,y):traffic,...},[(d,s),(d,s),...]
		NMK = [int(char) for char in fobj.readline().split()]
		Tcasei[0] = tuple(NMK)
		for j in range(1, NMK[1]+1):
			xy = [int(char) for char in fobj.readline().split()]
			Tcasei[1][tuple(xy)] = [int(char) for char in fobj.readline().split()]
		for j in range(1, NMK[2]+1):
			ds = [int(char) for char in fobj.readline().split()]
			Tcasei[2].append(tuple(ds))	
		Tcase.append(Tcasei)
	print "Read the file rightly"
	return Tcase

def sovle(Tcase):
	'''解决每一个case
	'''
	answers = [] #所有case的答案
	for casex in Tcase:
		N, M, K = casex[0]
		graph = casex[1]
		problems = casex[2]
		hours = [] #当前case的答案
		for problem in problems:
			hour = minihour(graph, d = problem[0], s = problem[1])
			hours.append(hour)
		answers.append(hours)
	return answers
	
def minihour(graph, d, s ):
	'''graph is a dict , each key is (x,y) tuple , and each item is the traffic
		between x->y in 0-23 o'clock
	   d, s is the problem: 1->d , stating at s o'clock
	'''
	# 找到当前问题的最短时间
	paths = find_path(graph,1,d) #假设d与1始终是不同的
	if not paths: #如果不存在路径，直接返回-1
		return -1
	minitime = min([ cacu_time(graph, path, s) for path in paths ]
	return minitime

def find_path(graph, source, target)：
	'''找出source,到target的所有路径
	'''
	# TODO:找出图中所有的source-target路径
	paths = []
	# egde_set = set(graph.keys())
	# for edge in edge_set:
	# 	if edge[0] == source:
	# 		path = [] 
	# 		path.append(source)
	return paths

def cacu_time(graph, path, s ):
	'''计算s时刻出发，走完path的最短时间
	'''
	assert path[0] == 1
	assert len(path) >=2
	current = s #当前这个城市的时间
	time = 0    #总共的耗时
	for i in range(len(path)-1):
		costi = graph[(path[i],path[i+1])][current] #要走的这一步路的耗时
		current = (current + costi) % 24            #到达下一个current的时间
		time += costi
	return time
	
	
if __name__ == "__main__":
	Tcase = read_input()
	answers = sovle(Tcase)
	for i in range(0,len(answers)):
		print "case #%d:"% i,
		print answers[i]
	