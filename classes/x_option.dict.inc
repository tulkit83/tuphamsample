<?php
    // file created on June 15, 2005, 12:42 pm

    // field specifications for table sample.x_option
    $fieldspec['option_id']                 = array('type' => 'string',
                                                    'size' => 8,
                                                    'pkey' => 'y',
                                                    'required' => 'y',
                                                    'uppercase' => 'y');
    $fieldspec['option_desc']               = array('type' => 'string',
                                                    'size' => 40,
                                                    'required' => 'y');
    $fieldspec['created_date']              = array('type' => 'datetime',
                                                    'size' => 20,
                                                    'required' => 'y',
                                                    'default' => '2003-01-01 12:00:00',
                                                    'autoinsert' => 'y',
                                                    'noedit' => 'y');
    $fieldspec['created_user']              = array('type' => 'string',
                                                    'size' => 16,
                                                    'autoinsert' => 'y',
                                                    'noedit' => 'y');
    $fieldspec['revised_date']              = array('type' => 'datetime',
                                                    'size' => 20,
                                                    'autoupdate' => 'y',
                                                    'noedit' => 'y');
    $fieldspec['revised_user']              = array('type' => 'string',
                                                    'size' => 16,
                                                    'autoupdate' => 'y',
                                                    'noedit' => 'y');

    // primary key details
    $this->primary_key                      = array('option_id');

    // unique key details
    $this->unique_keys                      = array();

    // child relationship details
    $this->child_relations[]                = array('child' => 'pers_opt_xref',
                                                    'type' => 'RES',
                                                    'fields' => array('option_id' => 'option_id'));

    // parent relationship details
    $this->parent_relations                 = array();

    // determines if database updates are recorded in an audit log
    $this->audit_logging                    = FALSE;

    // default sort sequence
    $this->default_orderby                  = 'option_id';

    // finished
?>