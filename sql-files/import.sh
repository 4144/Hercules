#!/bin/bash

export CMD="mysql -u root -p hercules"

$CMD <main.sql
#$CMD <item_db.sql
#$CMD <item_db2.sql
#$CMD <mob_db.sql
#$CMD <mob_db2.sql
$CMD <mob_skill_db.sql
$CMD <mob_skill_db2.sql
$CMD <logs.sql
$CMD <item_db_re.sql
$CMD <mob_db_re.sql
$CMD <mob_skill_db_re.sql
