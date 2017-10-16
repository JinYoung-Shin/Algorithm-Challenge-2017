import urllib3
import json

# get token
http = urllib3.PoolManager()
req_t = http.request('GET', 'http://api.welcome.kakao.com/token/UgDEmQ1z3Vlx7CrvZj11YgX8-FMqbKVbjjRkncg59M982j0dR')
val = req_t.status
if  val==200:
	# seed
	req_s = http.request(       'GET',
		              'http://api.welcome.kakao.com/seed',
		        headers = {'X-Auth-Token': req_t.data}
		)	
	seed_str = req_s.data.split('/')
	seed = []
	for i in range(1, len(seed_str)):
		if i%3==0:
			seed.append(seed_str[i][:-1])

	d0 = {}
	d1 = {}
	d2 = {}
	d3 = {}
	d4 = {}
	#document
	while 1:
		# ------------------------- 1.blog --------------------------------------
		req_d = http.request(       'GET',
				      'http://api.welcome.kakao.com/doc/blog/'+seed[0],
				headers = {'X-Auth-Token': req_t.data}
			)
		if req_d.status!=200:
			break;
		jdata = json.loads(req_d.data.decode('utf-8'))
		next = jdata['next_url'].split('/')[3]
		# data process
		d0_t = {}
		for i in jdata['images']:
			if(i['type'] == 'add'):
				if not i['id'] in d0:
					d0_t[i['id']] = 1
					d0[i['id']] = 1
			else:
				if i['id'] in d0:
					if i['id'] in d0_t:
						del d0[i['id']]
						del d0_t[i['id']]
					else:
						d0_t[i['id']] = 2
						del d0[i['id']]
		arr_a = []
		arr_d = []
		cnt_a = 0
		cnt_d = 0
		for i in d0_t:
			if d0_t[i] == 1:
				# add
				arr_a.append(i)
				cnt_a = cnt_a + 1
				if cnt_a == 50:
					tmp = arr_a[0]
					for i in arr_a[1:]:
						tmp = tmp + ',' + i
					req_f = http.request(       'GET',
				      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
					)
					jfeat = json.loads(req_f.data.decode('utf-8'))
					jfeat['data'] = jfeat.pop('features')	
					req_sv = http.request(       'POST',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(jfeat),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_a = 0
					del arr_a[:]	
			elif d0_t[i] == 2:
				# delete
				arr_d.append(i)
				cnt_d = cnt_d + 1
				if cnt_d == 50:
					tmp = '{ "data":['
					for i in arr_d:
						tmp = tmp + ' { "id":"' + i + '"},'
					tmp = tmp + ']}'			
					req_del = http.request(       'DELETE',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(tmp),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_d = 0
					del arr_d[:]
			else:
				print('Error')
		# add
		if len(arr_a) > 0:
			tmp = arr_a[0]
			for i in arr_a[1:]:
				tmp = tmp + ',' + i
			req_f = http.request(       'GET',
		      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
			)
			if(len(req_f.data) > 5): 
				jfeat = json.loads(req_f.data.decode('utf-8'))
				jfeat['data'] = jfeat.pop('features')	
				req_sv = http.request(       'POST',
			       'http://api.welcome.kakao.com/image/feature',
					body= json.dumps(jfeat),
					headers = {'X-Auth-Token': req_t.data}
				)
		# del
		if len(arr_d) > 0:
			tmp = '{ "data":['
			for i in arr_d:
				tmp = tmp + ' { "id":"' + i + '"},'
			tmp = tmp + ']}'
			req_del = http.request(       'DELETE',
			'http://api.welcome.kakao.com/image/feature',
				body= json.dumps(tmp),
				headers = {'X-Auth-Token': req_t.data}
			)
		# check it is last
		if seed[0] == next and not jdata['images']:
			print('break1')
		else:
			seed[0] = next;
		# ------------------------- 2.news --------------------------------------
		req_d = http.request(       'GET',
				      'http://api.welcome.kakao.com/doc/news/'+seed[1],
				headers = {'X-Auth-Token': req_t.data}
			)
		if req_d.status!=200:
			break;
		jdata = json.loads(req_d.data.decode('utf-8'))
		next = jdata['next_url'].split('/')[3]
		# data process
		d1_t = {}
		for i in jdata['images']:
			if(i['type'] == 'add'):
				if not i['id'] in d1:
					d1_t[i['id']] = 1
					d1[i['id']] = 1
			else:
				if i['id'] in d1:
					if i['id'] in d1_t:
						del d1[i['id']]
						del d1_t[i['id']]
					else:
						d1_t[i['id']] = 2
						del d1[i['id']]
		arr_a = []
		arr_d = []
		cnt_a = 0
		cnt_d = 0
		for i in d1_t:
			if d1_t[i] == 1:
				# add
				arr_a.append(i)
				cnt_a = cnt_a + 1
				if cnt_a == 50:
					tmp = arr_a[0]
					for i in arr_a[1:]:
						tmp = tmp + ',' + i
					req_f = http.request(       'GET',
				      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
					)
					jfeat = json.loads(req_f.data.decode('utf-8'))
					jfeat['data'] = jfeat.pop('features')	
					req_sv = http.request(       'POST',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(jfeat),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_a = 0
					del arr_a[:]	
			elif d1_t[i] == 2:
				# delete
				arr_d.append(i)
				cnt_d = cnt_d + 1
				if cnt_d == 50:
					tmp = '{ "data":['
					for i in arr_d:
						tmp = tmp + ' { "id":"' + i + '"},'
					tmp = tmp + ']}'			
					req_del = http.request(       'DELETE',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(tmp),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_d = 0
					del arr_d[:]
			else:
				print('Error')
		# add
		if len(arr_a) > 0:
			tmp = arr_a[0]
			for i in arr_a[1:]:
				tmp = tmp + ',' + i
			req_f = http.request(       'GET',
		      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
			)
			if(len(req_f.data) > 5): 
				jfeat = json.loads(req_f.data.decode('utf-8'))
				jfeat['data'] = jfeat.pop('features')	
				req_sv = http.request(       'POST',
			       'http://api.welcome.kakao.com/image/feature',
					body= json.dumps(jfeat),
					headers = {'X-Auth-Token': req_t.data}
				)
		# del
		if len(arr_d) > 0:
			tmp = '{ "data":['
			for i in arr_d:
				tmp = tmp + ' { "id":"' + i + '"},'
			tmp = tmp + ']}'
			req_del = http.request(       'DELETE',
			'http://api.welcome.kakao.com/image/feature',
				body= json.dumps(tmp),
				headers = {'X-Auth-Token': req_t.data}
			)
		# check it is last
		if seed[1] == next and not jdata['images']:
			print('break2')
		else:
			seed[1] = next;
		# ------------------------- 3.social --------------------------------------
		req_d = http.request(       'GET',
				      'http://api.welcome.kakao.com/doc/social/'+seed[2],
				headers = {'X-Auth-Token': req_t.data}
			)
		if req_d.status!=200:
			break;
		jdata = json.loads(req_d.data.decode('utf-8'))
		next = jdata['next_url'].split('/')[3]
		# data process
		d2_t = {}
		for i in jdata['images']:
			if(i['type'] == 'add'):
				if not i['id'] in d2:
					d2_t[i['id']] = 1
					d2[i['id']] = 1
			else:
				if i['id'] in d2:
					if i['id'] in d2_t:
						del d2[i['id']]
						del d2_t[i['id']]
					else:
						d2_t[i['id']] = 2
						del d2[i['id']]
		arr_a = []
		arr_d = []
		cnt_a = 0
		cnt_d = 0
		for i in d2_t:
			if d2_t[i] == 1:
				# add
				arr_a.append(i)
				cnt_a = cnt_a + 1
				if cnt_a == 50:
					tmp = arr_a[0]
					for i in arr_a[1:]:
						tmp = tmp + ',' + i
					req_f = http.request(       'GET',
				      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
					)
					jfeat = json.loads(req_f.data.decode('utf-8'))
					jfeat['data'] = jfeat.pop('features')	
					req_sv = http.request(       'POST',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(jfeat),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_a = 0
					del arr_a[:]	
			elif d2_t[i] == 2:
				# delete
				arr_d.append(i)
				cnt_d = cnt_d + 1
				if cnt_d == 50:
					tmp = '{ "data":['
					for i in arr_d:
						tmp = tmp + ' { "id":"' + i + '"},'
					tmp = tmp + ']}'			
					req_del = http.request(       'DELETE',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(tmp),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_d = 0
					del arr_d[:]
			else:
				print('Error')
		# add
		if len(arr_a) > 0:
			tmp = arr_a[0]
			for i in arr_a[1:]:
				tmp = tmp + ',' + i
			req_f = http.request(       'GET',
		      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
			)
			if(len(req_f.data) > 5): 
				jfeat = json.loads(req_f.data.decode('utf-8'))
				jfeat['data'] = jfeat.pop('features')	
				req_sv = http.request(       'POST',
			       'http://api.welcome.kakao.com/image/feature',
					body= json.dumps(jfeat),
					headers = {'X-Auth-Token': req_t.data}
				)
		# del
		if len(arr_d) > 0:
			tmp = '{ "data":['
			for i in arr_d:
				tmp = tmp + ' { "id":"' + i + '"},'
			tmp = tmp + ']}'
			req_del = http.request(       'DELETE',
			'http://api.welcome.kakao.com/image/feature',
				body= json.dumps(tmp),
				headers = {'X-Auth-Token': req_t.data}
			)
		# check it is last
		if seed[2] == next and not jdata['images']:
			print('break3')
		else:
			seed[2] = next;
		# ------------------------- 4.sport --------------------------------------
		req_d = http.request(       'GET',
				      'http://api.welcome.kakao.com/doc/sport/'+seed[3],
				headers = {'X-Auth-Token': req_t.data}
			)
		if req_d.status!=200:
			break;
		jdata = json.loads(req_d.data.decode('utf-8'))
		next = jdata['next_url'].split('/')[3]
		# data process
		d3_t = {}
		for i in jdata['images']:
			if(i['type'] == 'add'):
				if not i['id'] in d3:
					d3_t[i['id']] = 1
					d3[i['id']] = 1
			else:
				if i['id'] in d3:
					if i['id'] in d3_t:
						del d3[i['id']]
						del d3_t[i['id']]
					else:
						d3_t[i['id']] = 2
						del d3[i['id']]
		arr_a = []
		arr_d = []
		cnt_a = 0
		cnt_d = 0
		for i in d3_t:
			if d3_t[i] == 1:
				# add
				arr_a.append(i)
				cnt_a = cnt_a + 1
				if cnt_a == 50:
					tmp = arr_a[0]
					for i in arr_a[1:]:
						tmp = tmp + ',' + i
					req_f = http.request(       'GET',
				      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
					)
					jfeat = json.loads(req_f.data.decode('utf-8'))
					jfeat['data'] = jfeat.pop('features')	
					req_sv = http.request(       'POST',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(jfeat),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_a = 0
					del arr_a[:]	
			elif d3_t[i] == 2:
				# delete
				arr_d.append(i)
				cnt_d = cnt_d + 1
				if cnt_d == 50:
					tmp = '{ "data":['
					for i in arr_d:
						tmp = tmp + ' { "id":"' + i + '"},'
					tmp = tmp + ']}'			
					req_del = http.request(       'DELETE',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(tmp),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_d = 0
					del arr_d[:]
			else:
				print('Error')
		# add
		if len(arr_a) > 0:
			tmp = arr_a[0]
			for i in arr_a[1:]:
				tmp = tmp + ',' + i
			req_f = http.request(       'GET',
		      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
			)
			if(len(req_f.data) > 5): 
				jfeat = json.loads(req_f.data.decode('utf-8'))
				jfeat['data'] = jfeat.pop('features')	
				req_sv = http.request(       'POST',
			       'http://api.welcome.kakao.com/image/feature',
					body= json.dumps(jfeat),
					headers = {'X-Auth-Token': req_t.data}
				)
		# del
		if len(arr_d) > 0:
			tmp = '{ "data":['
			for i in arr_d:
				tmp = tmp + ' { "id":"' + i + '"},'
			tmp = tmp + ']}'
			req_del = http.request(       'DELETE',
			'http://api.welcome.kakao.com/image/feature',
				body= json.dumps(tmp),
				headers = {'X-Auth-Token': req_t.data}
			)
		# check it is last
		if seed[3] == next and not jdata['images']:
			print('break4')
		else:
			seed[3] = next;
		# ------------------------- 5.art --------------------------------------
		req_d = http.request(       'GET',
				      'http://api.welcome.kakao.com/doc/art/'+seed[4],
				headers = {'X-Auth-Token': req_t.data}
			)
		if req_d.status!=200:
			break;
		jdata = json.loads(req_d.data.decode('utf-8'))
		next = jdata['next_url'].split('/')[3]
		# data process
		d4_t = {}
		for i in jdata['images']:
			if(i['type'] == 'add'):
				if not i['id'] in d4:
					d4_t[i['id']] = 1
					d4[i['id']] = 1
			else:
				if i['id'] in d4:
					if i['id'] in d4_t:
						del d4[i['id']]
						del d4_t[i['id']]
					else:
						d4_t[i['id']] = 2
						del d4[i['id']]
		arr_a = []
		arr_d = []
		cnt_a = 0
		cnt_d = 0
		for i in d4_t:
			if d4_t[i] == 1:
				# add
				arr_a.append(i)
				cnt_a = cnt_a + 1
				if cnt_a == 50:
					tmp = arr_a[0]
					for i in arr_a[1:]:
						tmp = tmp + ',' + i
					req_f = http.request(       'GET',
				      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
					)
					jfeat = json.loads(req_f.data.decode('utf-8'))
					jfeat['data'] = jfeat.pop('features')	
					req_sv = http.request(       'POST',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(jfeat),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_a = 0
					del arr_a[:]	
			elif d4_t[i] == 2:
				# delete
				arr_d.append(i)
				cnt_d = cnt_d + 1
				if cnt_d == 50:
					tmp = '{ "data":['
					for i in arr_d:
						tmp = tmp + ' { "id":"' + i + '"},'
					tmp = tmp + ']}'			
					req_del = http.request(       'DELETE',
				       'http://api.welcome.kakao.com/image/feature',
						body= json.dumps(tmp),
						headers = {'X-Auth-Token': req_t.data}
					)
					cnt_d = 0
					del arr_d[:]
			else:
				print('Error')
		# add
		if len(arr_a) > 0:
			tmp = arr_a[0]
			for i in arr_a[1:]:
				tmp = tmp + ',' + i
			req_f = http.request(       'GET',
		      'http://api.welcome.kakao.com/image/feature?id='+tmp,
				headers = {'X-Auth-Token': req_t.data}
			)
			if(len(req_f.data) > 5): 
				jfeat = json.loads(req_f.data.decode('utf-8'))
				jfeat['data'] = jfeat.pop('features')	
				req_sv = http.request(       'POST',
			       'http://api.welcome.kakao.com/image/feature',
					body= json.dumps(jfeat),
					headers = {'X-Auth-Token': req_t.data}
				)
		# del
		if len(arr_d) > 0:
			tmp = '{ "data":['
			for i in arr_d:
				tmp = tmp + ' { "id":"' + i + '"},'
			tmp = tmp + ']}'
			req_del = http.request(       'DELETE',
			'http://api.welcome.kakao.com/image/feature',
				body= json.dumps(tmp),
				headers = {'X-Auth-Token': req_t.data}
			)
		# check it is last
		if seed[4] == next and not jdata['images']:
			print('break5')
		else:
			seed[4] = next;
elif val==400:
	print('Invalid login token')
elif val==403:
	print('Token already exists')
else:
	print('Error')
















