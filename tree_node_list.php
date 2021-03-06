<?php
//*****************************************************************************
// List the contents of the TREE_NODE table and allow the user to view/modify
// the contents by activating other screens via navigation buttons.
//*****************************************************************************

$outer_table = 'tree_level';				// name of outer table
$inner_table = 'tree_node';            	    // name of inner table
$screen   = 'tree_node.list.screen.inc';    // file identifying screen structure

// identify extra parameters for a JOIN
$outer_sql_select  = '';
$outer_sql_from    = '';
$outer_sql_where   = '';
$outer_sql_orderby = NULL;

$inner_sql_select  = '';
$inner_sql_from    = '';
$inner_sql_where   = '';
$inner_sql_orderby = '';

require 'std.list2.inc';                    // activate controller

?>
