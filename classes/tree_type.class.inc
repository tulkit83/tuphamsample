<?php
// *****************************************************************************
// Copyright 2003-2006 by A J Marston <http://www.tonymarston.net>
// *****************************************************************************
require_once 'std.table.class.inc';
class tree_type extends Default_table
{
    // ****************************************************************************
    function tree_type ()
    {
        // save directory name of current script
        $this->dirname   = dirname(__file__);

        $this->dbms_engine = $GLOBALS['dbms'];
        $this->dbname      = 'tuphamtest';
        $this->tablename   = 'tree_type';

        // call this method to get original field specifications
        // (note that they may be modified at runtime)
        $this->fieldspec = $this->getFieldSpec_original();

    } // tree_type

    // ****************************************************************************
    function _cm_getValRep ($item = '')
    // get Value/Representation list as an associative array.
    {
        $array = array();

        if ($item == 'tree_type_id') {
            // get data from the database
            $this->sql_select     = 'tree_type_id, tree_type_desc';
            $this->sql_orderby    = 'tree_type_id';
            $this->sql_ordery_seq = 'asc';
            $data = $this->getData(null);

            // convert each row into 'id=desc' in the output array
            foreach ($data as $row => $rowdata) {
                $rowvalues = array_values($rowdata);
                $array[$rowvalues[0]] = $rowvalues[1];
            } // foreach

            return $array;

        } // if

        return $array;

    } // _cm_getValRep

// ****************************************************************************
} // end class
// ****************************************************************************

?>
