<?php
//*****************************************************************************
// This will allow an occurrences of the TREE_LEVEL table to be deleted.
// The identity of the selected occurrence is passed down from the previous screen.
//*****************************************************************************

//DebugBreak();
$table_id = "tree_level";           	    // table id
$screen   = 'tree_level.detail.screen.inc'; // file identifying screen structure

require 'std.delete1.inc';                  // activate controller

?>
