SELECT prod.id, prod.name FROM products AS prod, categories AS cat WHERE cat.id=prod.id_categories AND cat.name like 'super%'