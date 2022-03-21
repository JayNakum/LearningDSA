w = 20
profit = 0.0
items = [{'Profit': 25, 'Weight': 18},
         {'Profit': 24, 'Weight': 15},
         {'Profit': 15, 'Weight': 10},
        ]

for item in items:
    item['Profit_by_Weight'] = item['Profit'] / item['Weight']

items.sort(key=lambda item: item['Profit_by_Weight'], reverse=True)

for i in range(1, len(items)):
    if(w > 0 and items[i]['Weight'] <= w):
        w = w - items[i]['Weight']
        profit = profit + items[i]['Profit']
    else:
        break
    if(w > 0):
        profit = profit + items[i]['Profit'] * (w / items[i]['Weight'])

print(items)
print(profit)